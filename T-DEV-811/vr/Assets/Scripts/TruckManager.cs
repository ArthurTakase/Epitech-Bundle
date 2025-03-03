using UnityEngine;
using UnityEngine.UI;
using Unity.AI.Navigation;
using System.Collections.Generic;
using System.Collections;

public class TruckManager : MonoBehaviour
{
    public GameObject truckPrefab;
    private GameObject truckGO;
    private Truck truck;
    public GameObject targetPrefab;
    [HideInInspector] public GameObject truckParent;
    private Button validateButton;
    private Image mapIndicator;
    public Sprite truckSprite;
    private new Camera camera;
    public NavMeshSurface navMeshSurface;
    public Queue<TruckStep> stepQueue = new();
    public TruckStep currentStep = null;

    public void Init(MapManager mapManager)
    {
        validateButton = mapManager.validateButton;
        mapIndicator = mapManager.MapIndicator;
        camera = mapManager.camera;

        // remove all click listeners
        validateButton.onClick.RemoveAllListeners();
        validateButton.onClick.AddListener(() => SpawnTruck());

        mapIndicator.sprite = truckSprite;
    }

    public void SpawnTruck()
    {
        Ray ray = camera.ViewportPointToRay(new Vector3(0.5f, 0.5f, 0));
        bool found = Physics.Raycast(ray, out RaycastHit hit);

        Vibration.VibratePop();

        if (!found)
        {
            Debug.Log("No map found");
            return;
        }

        truckParent = hit.transform.gameObject;

        if (truckGO != null) Destroy(truckGO);

        truckGO = Instantiate(truckPrefab, truckParent.transform.position, Quaternion.identity, truckParent.transform);
        truck = truckGO.GetComponent<Truck>();

        if (stepQueue.Count > 0) UpdateTarget();
    }

    public void AddStep(TruckStep truckStep)
    {
        // if truckStep.trashID is already in the queue, don't add it
        foreach (TruckStep step in stepQueue)
            if (step.trashID == truckStep.trashID) return;

        stepQueue.Enqueue(truckStep);
        if (currentStep == null) UpdateTarget();
    }

    public void UpdateTarget()
    {
        if (stepQueue.Count == 0)
        {
            currentStep = null;
            StartCoroutine(DelayedUpdateTarget(null, true));
            return;
        }

        currentStep = stepQueue.Dequeue();
        StartCoroutine(DelayedUpdateTarget(currentStep.trash.transform));
    }

    private IEnumerator DelayedUpdateTarget(Transform target, bool UpdateStartingPoint = false)
    {
        yield return null;

        if (truckGO == null)
        {
            truckGO = Instantiate(truckPrefab, truckParent.transform.position, Quaternion.identity, truckParent.transform);
            truck = truckGO.GetComponent<Truck>();
        }

        if (truck == null) truck = truckGO.GetComponent<Truck>();

        yield return null;

        if (UpdateStartingPoint)
        {
            if (truck.startingPoint == null)
            {
                truck.RemoveTarget();
                yield break;
            }

            truck.aIDestinationSetter.target = truck.startingPoint.transform;
        }
        else
        {
            if (target == null)
            {
                truck.RemoveTarget();
                yield break;
            }
            truck.aIDestinationSetter.target = target;
        }
    }

    public void ValidateStep(Trash trash)
    {
        if (trash.id != currentStep.trashID) return;

        currentStep.Validate();
        truck.RemoveTarget();
        UpdateTarget();
    }
}