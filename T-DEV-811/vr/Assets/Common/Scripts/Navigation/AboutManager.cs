/*============================================================================== 
Copyright (c) 2021 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.   
==============================================================================*/

using UnityEngine;
using UnityEngine.UI;
using TMPro;
using Vuforia;

public class AboutManager : MonoBehaviour
{
    public AboutScreenSample AboutScreenSampleInfo;
    
    public void LoadNextScene()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(UnityEngine.SceneManagement.SceneManager.GetActiveScene().buildIndex + 1);
    }

    void Start()
    {
        VuforiaApplication.Instance.OnVuforiaInitialized += OnVuforiaInitialized;
    }

    void Update()
    {
        if (Input.GetKeyUp(KeyCode.Return) || Input.GetKeyUp(KeyCode.JoystickButton0))
            LoadNextScene();

        if (Input.GetKeyUp(KeyCode.Escape))
        {
            if (Application.isEditor)
            {
#if UNITY_EDITOR
                UnityEditor.EditorApplication.isPlaying = false;
#endif
            }
            else
                Application.Quit();
        }
    }

    void OnDestroy()
    {
        VuforiaApplication.Instance.OnVuforiaInitialized -= OnVuforiaInitialized;
    }

    void OnVuforiaInitialized(VuforiaInitError error)
    {
        var aboutScreenInfo = new AboutScreenInfo();
        var title = aboutScreenInfo.GetTitle(AboutScreenSampleInfo.ToString());
        var description = aboutScreenInfo.GetDescription(AboutScreenSampleInfo.ToString());
        var textElements = GetComponentsInChildren<Text>();
        textElements[0].text = title;
        var textMeshProUGUI = GetComponentInChildren<TextMeshProUGUI>();
        textMeshProUGUI.text = description;
    }
}