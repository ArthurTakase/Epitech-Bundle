/*===============================================================================
Copyright (c) 2016-2018 PTC Inc. All Rights Reserved.
 
Copyright (c) 2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.
===============================================================================*/
using UnityEngine;
using Vuforia;

public class InitErrorHandler : MonoBehaviour
{
    string mKey;
    string mErrorMessage;
    
    const string ERROR_TITLE = "Vuforia Initialization Error";
    
    void Awake()
    {
        VuforiaApplication.Instance.OnVuforiaInitialized += OnVuforiaInitError;
    }

    void OnDestroy()
    { 
        VuforiaApplication.Instance.OnVuforiaInitialized -= OnVuforiaInitError;
    }
    
    void OnVuforiaInitError(VuforiaInitError error)
    {
        if (error != VuforiaInitError.NONE)
            ShowErrorMessage(error);
    }

    void ShowErrorMessage(VuforiaInitError errorCode)
    {
        switch (errorCode)
        {
            /* case VuforiaInitError.EXTERNAL_DEVICE_NOT_DETECTED:
                mErrorMessage =
                    "Failed to initialize Vuforia because this " +
                    "device is not docked with required external hardware.";
                break;*/
            case VuforiaInitError.LICENSE_CONFIG_MISSING_KEY:
                mErrorMessage =
                    "Vuforia App Key is missing. \n" +
                    "Please get a valid key, by logging into your account at " +
                    "developer.vuforia.com and creating a new project.";
                break;
            case VuforiaInitError.LICENSE_CONFIG_INVALID_KEY:
                mErrorMessage =
                    "Vuforia App key is invalid. \n" +
                    "Please get a valid key, by logging into your account at " +
                    "developer.vuforia.com and creating a new project. \n\n" +
                    GetKeyInfo();
                break;
            case VuforiaInitError.LICENSE_CONFIG_NO_NETWORK_TRANSIENT:
                mErrorMessage = "Unable to contact server. Please try again later.";
                break;
            case VuforiaInitError.LICENSE_CONFIG_NO_NETWORK_PERMANENT:
                mErrorMessage = "No network available. Please make sure you are connected to the Internet.";
                break;
            case VuforiaInitError.LICENSE_CONFIG_KEY_CANCELED:
                mErrorMessage =
                    "This App license key has been cancelled and may no longer be used. " +
                    "Please get a new license key. \n\n" +
                    GetKeyInfo();
                break;
            case VuforiaInitError.LICENSE_CONFIG_PRODUCT_TYPE_MISMATCH:
                mErrorMessage =
                    "Vuforia App key is not valid for this product. Please get a valid key, " +
                    "by logging into your account at developer.vuforia.com and choosing the " +
                    "right product type during project creation. \n\n" +
                    GetKeyInfo() + "\n\n" +
                    "Note that Universal Windows Platform (UWP) apps require " +
                    "a license key created on or after August 9th, 2016.";
                break;
            case VuforiaInitError.DEVICE_NOT_SUPPORTED:
                mErrorMessage = "Failed to initialize Vuforia Engine because this device is not supported.";
                break;
            case VuforiaInitError.PERMISSION_ERROR:
                mErrorMessage =
                    "One or more permissions required by Vuforia Engine are missing or not granted by user.\n" +
                    "For example, the user may have denied camera access to this app.\n" +
                    "In this case, you can enable camera access in Settings:\n" +
                    "Settings > Privacy > Camera > " + Application.productName + "\n" +
                    "Also verify that the camera is enabled in:\n" +
                    "Settings > General > Restrictions.";
                break;
            case VuforiaInitError.LICENSE_ERROR:
                mErrorMessage = "A valid license configuration is required.\n";
                break;
            case VuforiaInitError.INITIALIZATION:
            default:
                mErrorMessage = "Failed to initialize Vuforia Engine.";
                break;
        }
        
        mErrorMessage = "<color=red>" + errorCode.ToString().Replace("_", " ") + "</color>\n\n" + mErrorMessage;
        var errorTextConsole = mErrorMessage.Replace("<color=red>", "").Replace("</color>", "");
        Debug.LogError("Vuforia initialization failed: " + errorCode + "\n\n" + errorTextConsole);
        MessageBox.DisplayMessageBox(ERROR_TITLE, mErrorMessage, true, OnErrorDialogClose);
    }

    string GetKeyInfo()
    {
        var key = VuforiaConfiguration.Instance.Vuforia.LicenseKey;
        var keyInfo = "";
        if (key.Length > 10)
            keyInfo =
                "Your current key is <color=red>" + key.Length + "</color> characters in length. " +
                "It begins with <color=red>" + key.Substring(0, 5) + "</color> " +
                "and ends with <color=red>" + key.Substring(key.Length - 5, 5) + "</color>.";
        else
            keyInfo =
                "Your current key is <color=red>" + key.Length + "</color> characters in length. \n" +
                "The key is: <color=red>" + key + "</color>.";
        return keyInfo;
    }
    
    public void OnErrorDialogClose()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
}
