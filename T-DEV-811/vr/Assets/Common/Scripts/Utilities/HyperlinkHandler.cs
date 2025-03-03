/*===============================================================================
Copyright (c) 2018 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/

using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;
using UnityEngine.Events;

public class HyperlinkHandler : MonoBehaviour, IPointerClickHandler, IPointerUpHandler
{
    public UnityEvent OnActivateGameObjectEvent;

    TextMeshProUGUI mTextMeshPro;
    Camera mCamera;

    void Start()
    {
        mTextMeshPro = GetComponentInChildren<TextMeshProUGUI>();

        // Get a reference to the camera if Canvas Render Mode is not ScreenSpace Overlay
        var canvas = GetComponentInParent<Canvas>();
        mCamera = canvas.renderMode == RenderMode.ScreenSpaceOverlay ? null : canvas.worldCamera;
    }

    public void OnPointerClick(PointerEventData eventData)
    {
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        CheckIfLinkAndOpenURL();
    }

    void CheckIfLinkAndOpenURL()
    {
        var linkIndex = TMP_TextUtilities.FindIntersectingLink(mTextMeshPro, Input.mousePosition, mCamera);

        if (linkIndex != -1)
        {
            var linkInfo = mTextMeshPro.textInfo.linkInfo[linkIndex];
            var linkId = linkInfo.GetLinkID();

            if (linkId.StartsWith("http"))
            {
                Application.OpenURL(linkInfo.GetLinkID());
            }
            else if (linkId.StartsWith("event"))
            {
                var eventElements = linkId.Split(':');
                if (eventElements.Length != 2)
                {
                    Debug.LogError("Invalid event ID.");
                }
                else
                {
                    var eventId = eventElements[1];
                    if (eventId == "ACTIVATE_GAMEOBJECT")
                        OnActivateGameObjectEvent.Invoke();
                }
            }
        }
    }
}