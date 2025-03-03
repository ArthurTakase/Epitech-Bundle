using UnityEngine;
using System.Collections.Generic;
using System.Linq;

public class TrashManager : MonoBehaviour
{
    [HideInInspector] public List<Trash> trashes;
    [HideInInspector] public GameObject groundPlane;
    [HideInInspector] public TruckManager truckManager;
    private MapManager mapManager;
    public Sprite trashSprite;

    void Start()
    {
        trashes = FindObjectsOfType<Trash>().ToList();
        mapManager = GetComponent<MapManager>();
        truckManager = GetComponent<TruckManager>();
    }

    public void AddTrash(Trash trash)
    {
        trashes.Add(trash);
    }

    public void SetTrashStatus(int id)
    {
        SetTrashStatus(id, true, true, true, null);
    }

    public void SetTrashStatus(int id, bool isOpen, bool isFilled, bool isTilted, WS_Client wsClient)
    {
        Trash trash = trashes.FirstOrDefault(t => t.id == id);
        if (trash == null) return;

        trash.SetStatus(isOpen, isFilled, isTilted);

        if (isFilled)
        {
            TruckStep truckStep = new() { trash = trash, wsClient = wsClient, mapManager = mapManager, trashID = id };
            truckManager.AddStep(truckStep);
        }
    }

    public void AnchorAll()
    {
        foreach (var trash in trashes)
            trash.Anchor(groundPlane);

        mapManager.validateButton.onClick.RemoveAllListeners();
        mapManager.validateButton.onClick.AddListener(() => mapManager.truckManager.Init(mapManager));
    }
}