using UnityEngine;
using Vuforia;
using Image = UnityEngine.UI.Image;

public class Trash : MonoBehaviour
{
    public Image indicator;
    public bool isOpen;
    public bool isFilled;
    public bool isTilted;
    [SerializeField] private Sprite emptySprite;
    [SerializeField] private Sprite fullSprite;
    public int id;
    private bool updateMe = false;

    public void OnFound()
    {
        indicator.sprite = emptySprite;
        indicator.color = new Color32(255, 255, 255, 255);
        indicator.transform.rotation = Quaternion.Euler(0, 0, 0);

        TrashManager trashManager = FindObjectOfType<TrashManager>();
        trashManager.AddTrash(this);
    }

    public void Update()
    {
        if (!updateMe) return;

        indicator.sprite = isOpen ? fullSprite : emptySprite;
        indicator.color = isFilled ? Color.red : Color.white;
        indicator.transform.rotation = Quaternion.Euler(0, 0, isTilted ? -90 : 0);

        updateMe = false;
    }

    public void SetStatus(bool isOpen, bool isFilled, bool isTilted, bool force = false)
    {
        this.isOpen = isOpen;
        if (force) this.isFilled = isFilled;
        else this.isFilled = isFilled != false || this.isFilled;
        this.isTilted = isTilted;
        updateMe = true;
    }

    public void Anchor(GameObject groundPlane)
    {
        gameObject.transform.SetParent(groundPlane.transform);
        Destroy(GetComponent<DefaultObserverEventHandler>());
        Destroy(GetComponent<ImageTargetBehaviour>());

        gameObject.transform.SetPositionAndRotation(new Vector3(
            transform.position.x,
            groundPlane.transform.position.y,
            transform.position.z
        ), new Quaternion(0, 0, 0, 0));
    }
}