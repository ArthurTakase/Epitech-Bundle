using TMPro;
using UnityEngine;
using WebSocketSharp;
using UnityEngine.UI;
using System.Collections;

public class WS_Client : MonoBehaviour
{
    public string url = "wss://localhost:8081";
    public WebSocket ws;
    public TMP_InputField inputField;
    public Image indicator;
    public TrashManager trashManager;
    [SerializeField] private bool autoConnect = true;

    void Start()
    {
        inputField.text = url;
        if (autoConnect) Connect();
    }

    public void Connect()
    {
        StartCoroutine(ConnectCoroutine());
    }

    public IEnumerator ConnectCoroutine()
    {
        if (ws != null)
        {
            ws.Close();
            ws = null;
        }

        url = inputField.text;
        ws = new WebSocket(url);
        ws.SslConfiguration.EnabledSslProtocols = System.Security.Authentication.SslProtocols.Tls12;

        if (ws == null) yield break;

        ws.OnMessage += OnMessage;
        ws.Connect();

        while (ws.ReadyState == WebSocketState.Connecting)
        {
            indicator.color = Color.blue;
            yield return null;
        }

        if (ws.ReadyState == WebSocketState.Open) indicator.color = Color.green;
        else indicator.color = Color.red;
    }

    void OnMessage(object sender, MessageEventArgs e)
    {
        string data = e.Data;
        Debug.Log("Received: " + data);
        Data d = new(data);
        Debug.Log("Received: " + d.id + " " + d.isOpen + " " + d.isFilled + " " + d.isTilted);
        trashManager.SetTrashStatus(d.id, d.isOpen, d.isFilled, d.isTilted, this);
    }

    void OnDestroy()
    {
        if (ws == null)
            return;

        ws.Close();
        ws = null;
    }

    public void SendData(Data data)
    {
        if (ws == null)
        {
            indicator.color = Color.red;
            return;
        }

        Debug.Log("Sending: " + data.ToJson());
        ws.Send(data.ToJson());
        trashManager.SetTrashStatus(data.id, data.isOpen, data.isFilled, data.isTilted, this);
        indicator.color = Color.green;
    }

    public void SendData(string data)
    {
        if (ws == null)
            return;

        Debug.Log("Sending: " + data);
        ws.Send(data);
    }
}
