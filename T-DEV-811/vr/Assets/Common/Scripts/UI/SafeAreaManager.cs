/*===============================================================================
Copyright (c) 2019 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using System;
using UnityEngine;
using UnityEngine.UI;

public class SafeAreaManager : MonoBehaviour
{
    [Serializable]
    class SafeAreaRect
    {
        public RectTransform rectTransform = null;
        [Header("Apply Safe Area Constraints")]
        public bool top = false;
        public bool bottom = false;
    }

    [Header("Global Unsafe Area Settings (Per-Scene)")]
    [Tooltip("Unsafe Area Colors can be changed programmatically at runtime.")]
    [SerializeField] RectTransform topArea = null;
    [SerializeField] RectTransform bottomArea = null;
    [SerializeField] Color topAreaColor;
    [SerializeField] Color bottomAreaColor;
    [Tooltip("Safe Area Margin reduces the Safe Area by the specified amount at the Top/Bottom boundaries. " +
             "It is useful for testing Safe Area Behaviour in PlayMode.")]
    [Range(0,100)] // Max range value is arbitrary for example purposes
    [SerializeField] int SafeAreaMargin = 0;

    [Header("Apply Safe Area Constraints to RectTransforms")]
    [SerializeField] SafeAreaRect[] safeAreaRects = null;
    
    ScreenOrientation mLastOrientation;
    Rect mLastSafeArea = new Rect(0, 0, 0, 0);
    Rect mSafeArea;
    Image mTopAreaImage = null;
    Image mBottomAreaImage = null;
    bool ColorsChanged => (topAreaColor != mTopAreaImage.color) || (bottomAreaColor != mBottomAreaImage.color);

    void Awake()
    {
        if (!topArea || !bottomArea)
        {
            Debug.LogWarning("Either topArea or bottomArea is null. Programmatically getting the required references.");
            SetAreaRectTransforms();
        }
        
        // cache our unsafe area image components
        mTopAreaImage = topArea.GetComponent<Image>();
        mBottomAreaImage = bottomArea.GetComponent<Image>();

        // Set the unsafe area colors using Inspector values
        SetAreaColors(topAreaColor, bottomAreaColor);
        
        mSafeArea = GetSafeArea();
    }

    void SetAreaRectTransforms()
    {
        var images = GetComponentsInChildren<Image>();
        if (images.Length != 2)
        {
            Debug.LogError($"SafeAreaManager must have exactly two children with Image components attached.");
            return;
        }

        topArea = images[0].rectTransform;
        bottomArea = images[1].rectTransform;
    }
    
    Rect GetSafeArea()
    {
        return new Rect(
            Screen.safeArea.x, 
            Screen.safeArea.y + SafeAreaMargin,
            Screen.safeArea.width, 
            Screen.safeArea.height - (SafeAreaMargin * 2));
    }

    void Start()
    {
        mLastOrientation = Screen.orientation;

        Refresh();
    }

    void Update()
    {
        Refresh();
    }

    void Refresh()
    {
        mSafeArea = GetSafeArea();

        if ((mSafeArea != mLastSafeArea) || (Screen.orientation != mLastOrientation))
        {
            ApplySafeArea();
            UpdateUnsafeArea();
        }

        if (ColorsChanged)
            SetAreaColors(topAreaColor, bottomAreaColor);
    }

    void ApplySafeArea()
    {
        mLastSafeArea = mSafeArea;
        mLastOrientation = Screen.orientation;

        foreach (SafeAreaRect areaRect in safeAreaRects)
        {
            var anchorMin = mSafeArea.position;
            var anchorMax = mSafeArea.position + mSafeArea.size;

            anchorMin.x /= Screen.width;
            anchorMin.y = areaRect.bottom ? anchorMin.y / Screen.height : 0;
            anchorMax.x /= Screen.width;
            anchorMax.y = areaRect.top ? anchorMax.y / Screen.height : 1;

            if (Screen.orientation == ScreenOrientation.LandscapeLeft ||
                Screen.orientation == ScreenOrientation.LandscapeRight)
            {
                anchorMin.x = 0;
                anchorMax.x = 1;
            }

            if (areaRect.rectTransform != null)
            {
                areaRect.rectTransform.anchorMin = anchorMin;
                areaRect.rectTransform.anchorMax = anchorMax;
            }
        }
    }
    
    void UpdateUnsafeArea()
    {
        var anchorMin = mSafeArea.position;
        var anchorMax = mSafeArea.position + mSafeArea.size;

        anchorMin.x /= Screen.width;
        anchorMin.y /= Screen.height;
        anchorMax.x /= Screen.width;
        anchorMax.y /= Screen.height;

        SetUnsafeAreaSizes(anchorMin.y, anchorMax.y);
        
        SetAreaColors(topAreaColor, bottomAreaColor);
    }

    void SetUnsafeAreaSizes(float safeAreaAnchorMinY, float safeAreaAnchorMaxY)
    {
        topArea.anchorMin = new Vector2(0, safeAreaAnchorMaxY);
        topArea.anchorMax = Vector2.one;

        bottomArea.anchorMin = Vector2.zero;
        bottomArea.anchorMax = new Vector2(1, safeAreaAnchorMinY);
    }

    public void AddSafeAreaRect(RectTransform rect, bool applyTopConstraint, bool applyBottomConstraint)
    {
        Array.Resize(ref safeAreaRects, safeAreaRects.Length + 1);
        safeAreaRects[safeAreaRects.Length - 1] = new SafeAreaRect
        {
            rectTransform = rect,
            top = applyTopConstraint,
            bottom = applyBottomConstraint
        };

        ApplySafeArea();
    }

    public void SetAreasEnabled(bool topAreaEnabled, bool bottomAreaEnabled)
    {
        mTopAreaImage.enabled = topAreaEnabled;
        mBottomAreaImage.enabled = bottomAreaEnabled;
    }

    /// <summary>
    /// Sets the area colors programmatically and updates Inspector colors.
    /// </summary>
    /// <param name="topColor">Top color.</param>
    /// <param name="bottomColor">Bottom color.</param>
    public void SetAreaColors(Color topColor, Color bottomColor)
    {
        // update Inspector-level colors to match programmatic ones
        topAreaColor = topColor;
        bottomAreaColor = bottomColor;

        // assign the colors
        mTopAreaImage.color = topAreaColor;
        mBottomAreaImage.color = bottomAreaColor;
    }
}
