using UnityEngine;
using DG.Tweening;
using TMPro;
using UnityEngine.UI;
using System.Collections.Generic;

[System.Serializable]
public struct TutorielStep
{
    [TextArea(3, 10)]
    public string text;
    public Sprite icon;
}

public class Tutoriel : MonoBehaviour
{
    private int currentStep = 0;
    public Button buttonNext;
    public Button buttonPrevious;
    public Button buttonClose;
    public Image buttonPreviousIcon;
    public Image buttonNextIcon;
    public TextMeshProUGUI text;
    public TextMeshProUGUI textStep;
    private Transform menu;
    public Image icon;
    public Ease inEase = Ease.OutBounce;
    public Ease outEase = Ease.InBack;
    public float duration = 0.3f;
    public List<TutorielStep> steps = new();
    private Vector3 originalPosition;
    private Vector3 closedPosition;
    private bool isOpen = false;

    public void Start()
    {
        menu = gameObject.transform;
        originalPosition = menu.position;
        closedPosition = new Vector3(Screen.width * 2, originalPosition.y, originalPosition.z);
        menu.position = closedPosition;

        buttonNext.onClick.AddListener(NextStep);
        buttonPrevious.onClick.AddListener(PreviousStep);
        buttonClose.onClick.AddListener(Close);

        UpdateStep();
    }

    public void NextStep()
    {
        currentStep = (currentStep + 1) % steps.Count;
        UpdateStep();
    }

    public void PreviousStep()
    {
        currentStep = (currentStep - 1 + steps.Count) % steps.Count;
        UpdateStep();
    }

    public void UpdateStep()
    {
        text.text = steps[currentStep].text;
        icon.sprite = steps[currentStep].icon;

        if (currentStep == 0) buttonPreviousIcon.color = new Color(1, 1, 1, 0.1f);
        else buttonPreviousIcon.color = new Color(1, 1, 1, 1);
        buttonPrevious.interactable = currentStep > 0;

        if (currentStep == steps.Count - 1) buttonNextIcon.color = new Color(1, 1, 1, 0.5f);
        else buttonNextIcon.color = new Color(1, 1, 1, 1);
        buttonNext.interactable = currentStep < steps.Count - 1;

        textStep.text = $"{currentStep + 1}/{steps.Count}";
    }

    public void Toggle()
    {
        isOpen = !isOpen;
        if (isOpen) Open();
        else Close();
    }

    public void Close()
    {
        menu.DOMoveX(closedPosition.x, duration).SetEase(outEase);
    }

    public void Open()
    {
        menu.DOMoveX(originalPosition.x, duration).SetEase(inEase);
    }

}