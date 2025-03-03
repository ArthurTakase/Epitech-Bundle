using Pathfinding;
using UnityEngine;

public class Truck : MonoBehaviour
{
    public AIDestinationSetter aIDestinationSetter;
    public TruckManager truckManager;
    public GameObject startingPoint;

    void Start()
    {
        truckManager = FindObjectOfType<TruckManager>();

        startingPoint = new GameObject("StartingPoint");
        startingPoint.transform.position = transform.position;
        startingPoint.transform.SetParent(truckManager.truckParent.transform);
    }

    void OnDestroy()
    {
        Destroy(startingPoint);
    }

    public void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.CompareTag("Trash"))
        {
            Trash trash = other.gameObject.GetComponent<Trash>();
            truckManager.ValidateStep(trash);
        }
    }

    public void RemoveTarget()
    {
        aIDestinationSetter.target = null;
    }
}
