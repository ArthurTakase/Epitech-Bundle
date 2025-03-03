using UnityEngine;

public class MapElement : MonoBehaviour
{
    private MapManager mapManager;
    public string type;

    private void Start()
    {
        mapManager = FindObjectOfType<MapManager>();
    }

    public void OnFound()
    {
        mapManager.AddElement(this);
    }

    public void OnLost()
    {
    }

    public Vector2 Position()
    {
        return new Vector2(transform.position.x, transform.position.z);
    }
}