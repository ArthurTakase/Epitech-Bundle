using UnityEngine;
using System;

[Serializable]
public enum PlanerManagerState
{
    Idle,
    Place,
    RotateElements,
    Scale,
    Height,
    End
}

public class PlaneManager : MonoBehaviour
{
    Vector3 currentScale;
    Vector3 currentPosition;
    public GameObject planeFinder;
    private MapManager mapManager;
    public PlanerManagerState state = PlanerManagerState.Idle;

    void Start()
    {
        mapManager = FindObjectOfType<MapManager>();
    }

    public void FixedUpdate()
    {
        switch (state)
        {
            case PlanerManagerState.Idle: break;
            case PlanerManagerState.Place: Place(); break;
            case PlanerManagerState.RotateElements: RotateElements(); break;
            case PlanerManagerState.Scale: Scale(); break;
            case PlanerManagerState.Height: Height(); break;
            case PlanerManagerState.End:
                AstarPath.active.Scan();
                state = PlanerManagerState.Idle;
                mapManager.truckManager.Init(mapManager);
                break;
        }
    }

    public void Place()
    {
        if (Input.touchCount != 1) return;

        Touch touch = Input.GetTouch(0);

        if (touch.phase != TouchPhase.Moved) return;

        Vector3 cameraForward = mapManager.camera.transform.forward;
        cameraForward.y = 0;
        cameraForward.Normalize();

        Vector3 movement = new Vector3(touch.deltaPosition.x, 0, touch.deltaPosition.y) * 0.0001f;
        Vector3 relativeMovement = Quaternion.LookRotation(cameraForward) * movement;

        transform.position += relativeMovement;
    }

    public void Scale()
    {
        if (Input.touchCount == 2)
        {
            Touch touchZero = Input.GetTouch(0);
            Touch touchOne = Input.GetTouch(1);

            Vector2 touchZeroPrevPos = touchZero.position - touchZero.deltaPosition;
            Vector2 touchOnePrevPos = touchOne.position - touchOne.deltaPosition;

            float prevMagnitude = (touchZeroPrevPos - touchOnePrevPos).magnitude;
            float currentMagnitude = (touchZero.position - touchOne.position).magnitude;

            float difference = currentMagnitude - prevMagnitude;

            currentScale = transform.localScale;
            currentScale += new Vector3(difference * 0.0005f, difference * 0.0005f, difference * 0.0005f);

            // clamp scale
            currentScale.x = Mathf.Clamp(currentScale.x, 0.05f, 4f);
            currentScale.y = Mathf.Clamp(currentScale.y, 0.05f, 4f);
            currentScale.z = Mathf.Clamp(currentScale.z, 0.05f, 4f);

            transform.localScale = currentScale;
        }
    }

    public void Height()
    {
        if (Input.touchCount != 1) return;

        Touch touch = Input.GetTouch(0);

        if (touch.phase != TouchPhase.Moved) return;

        currentPosition = transform.position;
        currentPosition.y += touch.deltaPosition.y * 0.0001f;
        transform.position = currentPosition;
    }

    public void RotateElements()
    {
        if (Input.touchCount != 1) return;

        Touch touch = Input.GetTouch(0);

        if (touch.phase != TouchPhase.Moved) return;

        foreach (Transform element in transform)
        {
            Vector3 rotation = element.eulerAngles;
            rotation.y -= touch.deltaPosition.x * 0.01f;
            element.eulerAngles = rotation;
        }

    }

    public void LockPlaneFinder()
    {
        planeFinder.SetActive(!planeFinder.activeSelf);
    }

    public void SetState(int newState)
    {
        state = (PlanerManagerState)newState;
    }
}