/*===============================================================================
Copyright (c) 2019 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using System.Collections.Generic;
using UnityEngine;
using Vuforia;

public class AboutScreenInfo
{
    readonly Dictionary<string, string> mTitles;
    readonly Dictionary<string, string> mDescriptions;
    
    public AboutScreenInfo()
    {
        mTitles = new Dictionary<string, string>
        {
            { "ImageTargets", "Image Targets (from database)" },
            { "InstantImageTargets", "Instant Image Targets" },
            { "VuMarks", "VuMarks" },
            { "CylinderTargets", "Cylinder Targets" },
            { "MultiTargets", "Multi Targets" },
            { "CloudReco", "Cloud Reco" },
            { "ModelTargetsStandard", "Model Targets (Standard)" },
            { "ModelTargetsAdvanced", "Model Targets (Advanced)" },
            { "GroundPlane", "Ground Plane" },
            { "MidAir", "Mid-Air" },
            { "ModelTargetsTest", "Model Targets Test" },
            { "AreaTargets", "Area Targets" },
            { "AreaTargetCapture", "Area Target Capture" },
            { "Barcodes", "Barcodes" },
        };

        var vuforiaVersion = VuforiaApplication.GetVuforiaLibraryVersion();
        
        var unityVersion = Application.unityVersion;
        Debug.Log("Vuforia Engine " + vuforiaVersion + "\nUnity " + unityVersion);
        var fusionProvider = VuforiaRuntimeUtilities.GetActiveFusionProvider().ToString();

        var description = "\n<size=26>Description:</size>";
        var keyFunctionality = "<size=26>Key Functionality:</size>";
        var targets = "<size=26>Targets:</size>";
        var instructions = "<size=26>Instructions:</size>";
        var footer =
            "<size=26>Version Info:</size>" +
            "\n• Vuforia Engine " + vuforiaVersion +
            "\n• Unity " + unityVersion +
            "\n" +
            "\n<size=26>Vuforia Info:</size>" +
            "\n• Fusion Provider: " + fusionProvider.Replace("_", " ") +
            "\n" +
            "\n<size=26>System Info:</size>" +
            "\n• Device Name: " + SystemInfo.deviceName +
            "\n• Device Model: " + SystemInfo.deviceModel +
            "\n• Operating System: " + SystemInfo.operatingSystem +
            "\n• System Memory: " + SystemInfo.systemMemorySize +
            "\n• Processor Count: " + SystemInfo.processorCount +
            "\n• Processor Frequency: " + SystemInfo.processorFrequency +
            "\n" +
            "\n<size=26>Graphics Info:</size>" +
            "\n• Graphics Memory: " + SystemInfo.graphicsMemorySize +
            "\n• Device Name: " + SystemInfo.graphicsDeviceName +
            "\n• Device Vendor: " + SystemInfo.graphicsDeviceVendor +
            "\n• Device Type: " + SystemInfo.graphicsDeviceType +
            "\n• Device Version: " + SystemInfo.graphicsDeviceVersion +
            "\n• MultiThreaded: " + SystemInfo.graphicsMultiThreaded +
            "\n" +
            "\n<size=26>Links:</size>" +
            "\n• <link=https://developer.vuforia.com/legal/vuforia-developer-agreement><color=blue><u>Developer Agreement</u></color></link>" +
            "\n• <link=https://developer.vuforia.com/legal/privacy><color=blue><u>Privacy Policy</u></color></link>" +
            "\n• <link=https://developer.vuforia.com/legal/EULA><color=blue><u>Terms of Use</u></color></link>" +
            "\n• <link=https://developer.vuforia.com/legal/statistics><color=blue><u>Statistics</u></color></link>" +
            "\n\n" +
            "© 2023 PTC Inc. All Rights Reserved." +
            "\n";
        var targetPDFsURL = "<link=https://library.vuforia.com/content/vuforia-library/en/articles/Solution/sample-apps-target-pdfs.html>";

        // Init our Description Strings

        mDescriptions = new Dictionary<string, string>();

        // Image Targets

        mDescriptions.Add(
            "ImageTargets",
            description +
            "\nThe Image Targets sample shows how to detect an image " +
            "target and render a simple 3D object on top of it." +
            "\n\n" +
            keyFunctionality +
            "\n• Simultaneous detection and tracking of multiple targets" +
            "\n• Activate Extended Tracking" +
            "\n• Manage camera functions: flash and continuous autofocus" +
            "\n\n" +
            targets +
            "\n• " + targetPDFsURL +
            "<color=blue><u>Target PDFs</u></color></link>" +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n\n" +
            footer + "\n");

        // Instant Image Targets
        
        // determine if a license key has been set
        var licenseKeyNote = string.Empty;

        if (string.IsNullOrEmpty(VuforiaConfiguration.Instance.Vuforia.LicenseKey))
            licenseKeyNote = "\n<color=red>Please configure a license key in the Vuforia Configuration!</color>";
        else
            licenseKeyNote = "\n<#23B200>A license key has been set.</color>";
        mDescriptions.Add(
            "InstantImageTargets",
            description +
            "\nThe Instant Image Targets sample shows how to create an image " +
            "target from image assets loaded at runtime without creating a " +
            "target manager database." + 
            "\nThis sample requires a license key from:" +
            "\n<link=https://developer.vuforia.com/license-manager><color=blue><u>https://developer.vuforia.com/license-manager</u></color></link>" +
            licenseKeyNote + 
            "\n\n" +
            keyFunctionality +
            "\n• Creating an image target from image assets" +
            "\n• Simultaneous detection and tracking of multiple targets" +
            "\n• Activate Extended Tracking" +
            "\n• Manage camera functions: flash and continuous autofocus" +
            "\n\n" +
            targets +
            "\n• " + targetPDFsURL +
            "<color=blue><u>Target PDFs</u></color></link>" +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n\n" +
            footer + "\n");

        // VuMark
        mDescriptions.Add(
            "VuMarks",
            description +
            "\nThe VuMarks sample shows how to detect and track VuMarks." +
            "\n\n" +
            keyFunctionality +
            "\n• Simultaneous detection and tracking of multiple VuMarks" +
            "\n• Load and activate a VuMark target" +
            "\n• Activate Extended Tracking" +
            "\n• Render an outline when a VuMark is detected" +
            "\n\n" +
            targets +
            "\n• " + targetPDFsURL +
            "<color=blue><u>Target PDFs</u></color></link>" +
            "\n\n" +
            instructions +
            "\n• Point device at VuMark" +
            "\n• Double tap to focus" +
            "\n• Tap window showing VuMark ID to dismiss" +
            "\n\n" +
            footer + "\n");

        // Cylinder Targets
        mDescriptions.Add(
            "CylinderTargets",
            description +
            "\nThe Cylinder Targets sample shows how to detect a cylindrical " +
            "target and animate a 3D object around the circumference of the cylinder." +
            "\n\n" +
            keyFunctionality +
            "\n• Detection and tracking of a cylinder target" +
            "\n• Occlusion handling" +
            "\n\n" +
            targets +
            "\n• " + targetPDFsURL +
            "<color=blue><u>Target PDFs</u></color></link>" +
            "\n\n" +
            "Print target and wrap around a standard soda can." +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n\n" +
            footer + "\n");

        // Multi Targets
        mDescriptions.Add(
            "MultiTargets",
            description +
            "\nThe Multi Targets sample shows how to detect a simple cuboid 3D shape " +
            "and animate a 3D object around the shape." +
            "\n\n" +
            keyFunctionality +
            "\n• Detection and tracking of cuboid 3D shape" +
            "\n• Occlusion handling" +
            "\n\n" +
            targets +
            "\n• " + targetPDFsURL +
            "<color=blue><u>Target PDFs</u></color></link>" +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n\n" +
            footer + "\n");
        
        // Cloud Reco
        mDescriptions.Add(
            "CloudReco",
            description +
            "\nThe Cloud Reco sample shows how to use the cloud recognition service to " +
            "recognize targets located in a cloud database." +
            "\n\n" +
            keyFunctionality +
            "\n• Manage detection and tracking of cloud based image targets" +
            "\n• Activate Extended Tracking" +
            "\n\n" +
            targets +
            "\n• " + targetPDFsURL +
            "<color=blue><u>Target PDFs</u></color></link>" +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n\n" +
            footer + "\n");
        
        // Model Targets (Standard)
        mDescriptions.Add(
            "ModelTargetsStandard",
            description +
            "\nThe Model Targets (Standard) Sample shows how to detect a 3D object and " +
            "render a simple 3D representation over it. The sample demonstrates " +
            "how Standard DataSets work." +
            "\n\n" +
            keyFunctionality +
            "\n• Standard Model Target: Loads a Model Target with multiple Guide Views " +
            "that can be cycled with the click of a button and used to pick which view " +
            "to detect of the physical model" +
            "\n\n" +
            targets +
            "\n• Model Target: Toy Model (Polaris RZR)" +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n• Cycle through different guide views to match the current pose of the physical model" + 
            "\n• Change the Detection Position if needed" +
            "\n\n" +
            footer + "\n");
        
        // Model Targets (Advanced)
        mDescriptions.Add(
            "ModelTargetsAdvanced",
            description +
            "\nThe Model Targets (Advanced) Sample shows how to detect a 3D object and " +
            "render a simple 3D representation over it. The sample demonstrates " +
            "how Advanced DataSets work." +
            "\n\n" +
            keyFunctionality +
            "\n• Advanced Model Target: Loads two Model Targets that have automatic " +
            "detection from arbitrary views and snapping of Guide Views to the physical models" +
            "\n• Automatic 3D object tracking after successful detection" +
            "\n• Extended Tracking when target is not visible in the camera view" +
            "\n\n" +
            targets +
            "\n• Model Target: Toy Model (Polaris RZR)" +
            "\n• and 3D Printed Model (Mars Lander)" +
            "\n\n" +
            instructions +
            "\n• Point camera at target to view" +
            "\n• Double tap to focus" +
            "\n• Change the Detection Position if needed" +
            "\n\n" +
            footer + "\n");

        // Ground Plane
        mDescriptions.Add(
            "GroundPlane",
            description +
            "\nThe Ground Plane sample demonstrates how to place " +
            "content on surfaces using anchor points." +
            "\n\n" +
            keyFunctionality +
            "\n• Hit testing places the Chair on an intersecting plane in the environment." +
            "\n\n" +
            targets +
            "\n• None required" +
            "\n\n" +
            instructions +
            "\n• Launch the app and view your environment" +
            "\n• Look around until the indicator shows that you have found a surface" +
            "\n• Tap to place Chair on the ground" +
            "\n• Drag with one finger to move Chair along ground" +
            "\n• Touch and hold with two fingers to rotate Chair" +
            "\n\n" +
            footer + "\n");

        // Mid Air
        mDescriptions.Add(
            "MidAir",
            description +
            "\nThe Mid Air sample demonstrates how to place " +
            "content in mid-air using anchor points." +
            "\n\n" +
            keyFunctionality +
            "\n• Mid-Air anchoring places the drone on an anchor point created " +
            "at a fixed distance relative to the user." +
            "\n\n" +
            targets +
            "\n• None required" +
            "\n\n" +
            instructions +
            "\n• Launch the app and view your environment" +
            "\n• Look around until the indicator shows that you have found a surface" +
            "\n• Tap to place Drone in the air" +
            "\n• Tap again to move Drone to the desired position" +
            "\n\n" +
            footer + "\n");

        // Model Targets Test
        mDescriptions.Add(
            "ModelTargetsTest",
            description +
            "\nThe Model Targets Test app allows you to detect " +
            "and track a Model Target out of a set of multiple targets." +
#if ENABLE_MODEL_TARGETS_TEST_APP_DIAGNOSTICS
            " You can also record tracking data and report feedback to Vuforia." +
#endif
            "\n\n" +
            keyFunctionality +
            "\n• Detection and tracking of Model Targets" +
#if ENABLE_MODEL_TARGETS_TEST_APP_DIAGNOSTICS
            "\n• Collection and sending of SDK-generated data for later analysis and support" +
            "\n• Screenshot Capture" +
#endif
            "\n• Tracker reset" +
            "\n\n" +
            targets +
            "\n• Model Target: 3D Printed Model (Mars Lander)" +
            "\n\n" +
            instructions +
            "\n• Point camera at 3D object to start tracking" +
            "\n• Double tap to focus" +
            "\n• Select TrackingOptimization to be used" +
            "\n• Choose Static Device Tracker mode" +
            "\n• Change colors to visualize tracking states" +
            "\n• Modify line thickness for visibility" +
            "\n\n" +
            "<size=26>Compatible Devices:</size>" +
            "\n• <link=https://library.vuforia.com/articles/Solution/vuforia-fusion-supported-devices.html><color=blue><u>Vuforia Fusion Compatible Devices</u></color></link>" +
            "\n\n" +
            "<size=26>Additional Info:</size>" +
            "\n• <link=event:ACTIVATE_GAMEOBJECT><color=blue><u>3rd Party Notice</u></color></link>" +
#if ENABLE_MODEL_TARGETS_TEST_APP_DIAGNOSTICS
            "\n• <link=https://developer.vuforia.com/legal/statistics_CAD><color=blue><u>Statistics: CAD</u></color></link>" +
#endif
            "\n\n" +
            footer + "\n");
        
        // Area Targets
        mDescriptions.Add(
            "AreaTargets",
            description +
            "\nArea Targets is a Vuforia powered environment tracking feature " +
            "that enables you to track and augment your surroundings. By using " +
            "a 3D-scan as an accurate model of the space to create an " +
            "Area Target Device Database, you can deliver augmentations " +
            "to stationary objects in the scanned environment. " +
            "\n\n" +
            keyFunctionality +
            "\n• The Area Target representing the space which is activated to " + 
            "localize within the environment, " +
            "\n• Individual machines show associated IoT-data on labels " + 
            "that react to the user's presence, and " +
            "\n• A navigation path is drawn to demonstrate navigation " + 
            "guidance in scanned environments with the help of Unity's navMesh." +
            "\n\n" +
            targets +
            "\n• Area Target: AreaTargetSample (see NOTE below)" +
            "\n\n" +
            instructions +
            "\n• Point camera at the environment to view" +
            "\n• Double tap to focus" +
            "\n• Locate the IoT-labels on the machines!" +
            "\n• Use navigation guidance to find your way!" +
            "\n\n" +
            "\nNOTE: The Area Targets sample contains the Area Target " +
            "of PTC's Customer Experience Centre in our HQ with an " +
            "associated recording to play back in Unity Editor. If you " +
            "like to try in your space, you will need to create " +
            "an Area Target with one of our supported methods." +
            "\n\n" +
            footer + "\n");
        
        // Area Target Capture
        mDescriptions.Add(
            "AreaTargetCapture",
            description +
            "\nThe Area Targets Capture sample shows how to " +
            "capture an environment on LiDAR enabled devices, " +
            "and test the ad-hoc generated Area Target." +
            "\n\n" +
            keyFunctionality +
            "\n• Capture Area Targets using the Capture Prefab" +
            "\n• Test generated target" +
            "\n\n" +
            targets +
            "\n• This sample does not contain a pre-recorded " +
            "target, capture your own targets by hitting Record." +
            "\n\n" +
            instructions +
            "\n• Start capture using the Record button" +
            "\n• Name a target" +
            "\n• Start/Pause/Resume/Stop capture process" +
            "\n• Test generated target." +
            "\n\n" +
            footer + "\n");

        // Barcodes
        mDescriptions.Add(
            "Barcodes",
            description +
            "\nThe Barcode sample shows how to activate 1D/2D " +
            "barcode scanning, select the barcode the user is " +
            "aiming at and display detection results." +
            "\n\n" +
            keyFunctionality +
            "\n• Select camera settings optimized for detection of small objects" + 
            "\n• Activate Barcode detection" +
            "\n• Display a barcode search reticle" + 
            "\n• Select one out of multiple barcode detections" + 
            "\n• Render the outline of a barcode detection" + 
            "\n• Test generated target" +
            "\n\n" +
            instructions +
            "\n• Activate 1D or 2D barcode detection in the menu" +
            "\n• Point at barcodes" +
            "\n\n" +
            footer + "\n");
    }
    
    public string GetTitle(string titleKey)
    {
        return GetValueFromDictionary(mTitles, titleKey);
    }

    public string GetDescription(string descriptionKey)
    {
        return GetValueFromDictionary(mDescriptions, descriptionKey);
    }

    static string GetValueFromDictionary(Dictionary<string, string> dictionary, string key)
    {
        return dictionary.TryGetValue(key, out var value) ? value : "Key not found.";
    }
}
