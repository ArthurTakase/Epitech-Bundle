using System;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;
using Vuforia;
using Image = UnityEngine.UI.Image;

[Serializable]
public struct Map3x3
{
    public List<List<MapElement>> map;
}

public class MapManager : MonoBehaviour
{
    public TextMeshProUGUI debugText;

    public new Camera camera;
    public List<MapElement> mapElements = new();
    public Image MapIndicator;
    public Button validateButton;
    public GameObject groundPlane;
    public TruckManager truckManager;
    public Sprite scanSprite;
    public PlaneManager planeManager;
    public TrashManager trashManager;

    public void Start()
    {
        Vibration.Init();

        MapIndicator.sprite = scanSprite;
        validateButton.interactable = true;

        validateButton.onClick.RemoveAllListeners();
        validateButton.onClick.AddListener(() => AnchorAll());

        truckManager = GetComponent<TruckManager>();
        planeManager = FindObjectOfType<PlaneManager>();
        trashManager = GetComponent<TrashManager>();
    }

    public void AnchorAll()
    {
        foreach (var element in mapElements)
        {
            AnchorElement(element);
            Destroy(element.gameObject);
        }

        planeManager.state = PlanerManagerState.Place;

        validateButton.onClick.RemoveAllListeners();
        validateButton.onClick.AddListener(() => trashManager.AnchorAll());

        MapIndicator.sprite = trashManager.trashSprite;
    }

    public void AddElement(MapElement element)
    {
        if (element == null) return;
        if (mapElements.Contains(element)) return;
        mapElements.Add(element);
    }

    public void AnchorElement(MapElement element)
    {
        GameObject clone = Instantiate(element.gameObject, groundPlane.transform);
        clone.transform.SetPositionAndRotation(new()
        {
            x = element.transform.position.x,
            y = groundPlane.transform.position.y,
            z = element.transform.position.z
        }, new()
        {
            x = 0,
            y = 0,
            z = 0
        });
        Destroy(clone.GetComponent<DefaultObserverEventHandler>());
        Destroy(clone.GetComponent<ImageTargetBehaviour>());
    }
}