using UnityEngine;
using UnityEngine.SceneManagement;
using TMPro;
using System.Collections.Generic;
using DG.Tweening;
using System.Collections;

public class UIActions : MonoBehaviour
{
    public TextMeshProUGUI debugText;
    public GameObject menu;
    public List<Vector3> menuElementsOriginalPositions = new();

    public void Start()
    {
        foreach (Transform child in menu.transform)
            menuElementsOriginalPositions.Add(child.position);

        StartCoroutine(MenuAnimate(false));
    }

    public void ResetScene()
    {
        Vibration.VibratePop();
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    public void ResetDebugText()
    {
        Vibration.VibratePop();
        debugText.text = "";
    }

    public void ToggleMenu()
    {
        Vibration.VibratePop();
        StartCoroutine(MenuAnimate(!menu.activeSelf));
    }

    public void Vibrate()
    {
        Vibration.VibratePop();
    }

    private IEnumerator MenuAnimate(bool show = true)
    {
        if (show == true) menu.SetActive(true);

        int nbChildren = menu.transform.childCount;
        int currentChild = 0;

        foreach (Transform child in menu.transform)
        {
            int index = child.GetSiblingIndex();
            Vector3 originalPosition = menuElementsOriginalPositions[index];
            Vector3 centerPosition = menu.transform.position;
            Vector3 targetPosition = show ? originalPosition : centerPosition;
            Ease ease = show ? Ease.OutBack : Ease.InBack;

            child
                .DOMove(targetPosition, 0.3f)
                .SetEase(ease)
                .SetDelay(index * 0.05f)
                .OnStart(() => child.gameObject.SetActive(true))
                .OnComplete(() =>
                {
                    currentChild++;
                    child.gameObject.SetActive(show);
                });
        }

        yield return new WaitUntil(() => currentChild == nbChildren);

        menu.SetActive(show);
    }
}