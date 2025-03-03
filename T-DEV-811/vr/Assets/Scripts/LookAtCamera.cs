using UnityEngine;

public class LookAtCamera : MonoBehaviour
{
    public Camera mainCamera;

    public void FixedUpdate()
    {
        transform.LookAt(mainCamera.transform);
        transform.Rotate(0, 180, 0);
    }
}
