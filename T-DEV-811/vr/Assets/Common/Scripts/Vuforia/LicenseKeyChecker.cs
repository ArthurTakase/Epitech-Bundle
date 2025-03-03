/*==============================================================================
Copyright (c) 2021 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
==============================================================================*/

using UnityEngine;
using UnityEngine.Serialization;
using Vuforia;

internal class LicenseKeyChecker : MonoBehaviour
{
    public string VuforiaFeature = "Instant Image Targets";
    void Awake()
    {
        if (string.IsNullOrEmpty(VuforiaConfiguration.Instance.Vuforia.LicenseKey))
            MessageBox.DisplayMessageBox("Missing License Key", "The " + VuforiaFeature + " feature requires a Vuforia Engine license key to be set. Please visit developer.vuforia.com to register for free and get a license key.", false, null);
    }
}