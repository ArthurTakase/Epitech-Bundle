/*===============================================================================
Copyright (c) 2016-2019 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/
using UnityEngine;
using UnityEngine.UI;
using Vuforia;
using TMPro;

public class SamplesMainMenu : MonoBehaviour
{
    bool IsAboutScreenVisible => aboutCanvas.sortingOrder > menuCanvas.sortingOrder;

    [SerializeField] Canvas menuCanvas = null;
    [SerializeField] Canvas aboutCanvas = null;
    [SerializeField] Text aboutTitle = null;
    [SerializeField] TextMeshProUGUI aboutDescription = null;

    AboutScreenInfo mAboutScreenInfo;
    SafeAreaManager mSafeAreaManager;
    readonly Color mLightGrey = new Color(220f / 255f, 220f / 255f, 220f / 255f);

    void Start()
    {
        VuforiaApplication.Instance.OnVuforiaInitialized += OnVuforiaInitialized;

        mSafeAreaManager = FindObjectOfType<SafeAreaManager>();

        if (mSafeAreaManager)
        {
            mSafeAreaManager.SetAreaColors(mLightGrey, Color.white);
            mSafeAreaManager.SetAreasEnabled(true, true);
        }
    }

    void Update()
    {
        if (Input.GetKeyUp(KeyCode.Escape))
        {
            if (IsAboutScreenVisible)
                OnBackButton();
            else
                QuitApp();
        }
        else if (Input.GetKeyUp(KeyCode.Return) || Input.GetKeyUp(KeyCode.JoystickButton0))
        {
            if (IsAboutScreenVisible)
            {
                // In Unity 'Return' key same as clicking next button on About Screen
                // On ODG R7, JoystickButton0 is the Trackpad select button
                OnStartAR();
            }
        }
    }

    void OnDestroy()
    {
        VuforiaApplication.Instance.OnVuforiaInitialized -= OnVuforiaInitialized;
    }

    void OnVuforiaInitialized(VuforiaInitError error)
    {
        // initialize if null
        if (mAboutScreenInfo == null)
            mAboutScreenInfo = new AboutScreenInfo();
    }
    
    public void OnStartAR()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene("2-Loading");
    }

    public void OnBackButton()
    {
        ShowAboutScreen(false);
    }

    public void OnMenuItemSelected(string selectedMenuItem)
    {
        if (selectedMenuItem == string.Empty)
            return;
        // Set the scene to be loaded.
        LoadingScreen.SceneToLoad = "3-" + selectedMenuItem;

        // Populate the about screen info.
        aboutTitle.text = mAboutScreenInfo.GetTitle(selectedMenuItem);
        aboutDescription.text = mAboutScreenInfo.GetDescription(selectedMenuItem);

        // Display the about screen.
        ShowAboutScreen(true);
    }

    void ShowAboutScreen(bool showAboutScreen)
    {
        if (showAboutScreen)
        {
            // Place About canvas in front of Menu canvas
            aboutCanvas.sortingOrder = menuCanvas.sortingOrder + 1;

            if (mSafeAreaManager)
            {
                mSafeAreaManager.SetAreaColors(mLightGrey, Color.clear);
                mSafeAreaManager.SetAreasEnabled(true, false);
            }
        }
        else
        {
            // Place About canvas behind Menu canvas
            aboutCanvas.sortingOrder = menuCanvas.sortingOrder - 1;

            if (mSafeAreaManager)
            {
                mSafeAreaManager.SetAreaColors(mLightGrey, Color.white);
                mSafeAreaManager.SetAreasEnabled(true, true);
            }
        }
    }

    void QuitApp()
    {
        if (Application.isEditor)
        {
#if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
#endif
        }
        else
        {
            Application.Quit();
        }
    }
}
