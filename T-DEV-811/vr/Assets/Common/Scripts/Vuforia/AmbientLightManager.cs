/*===============================================================================
Copyright (c) 2019 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other 
countries.
===============================================================================*/

using UnityEngine;
using Vuforia;

[RequireComponent(typeof(Light))]
public class AmbientLightManager : MonoBehaviour
{
    Light mSceneLight;
    float mMaxIntensity;
    World mVuforiaWorld;
    
    void Start()
    {
        VuforiaApplication.Instance.OnVuforiaStarted += OnVuforiaStarted;

        mSceneLight = GetComponent<Light>();
        mMaxIntensity = mSceneLight.intensity;
    }

    void Update()
    {
        if (mVuforiaWorld != null && mVuforiaWorld.IlluminationData.AmbientIntensity != null)
        {
            var intensity = mVuforiaWorld.IlluminationData.AmbientIntensity.Value / 1000f;

            // Set light intensity to range between 0 and it's max intensity value
            mSceneLight.intensity = Mathf.Clamp(intensity, 0, mMaxIntensity);

            // Set to scene's ambient light intensity and clamp between 0 and 1
            RenderSettings.ambientIntensity = Mathf.Clamp01(intensity);
        }
        else
            mSceneLight.intensity = mMaxIntensity;
    }

    void OnDestroy()
    {
        VuforiaApplication.Instance.OnVuforiaStarted -= OnVuforiaStarted;
    }

    void OnVuforiaStarted()
    {
        mVuforiaWorld = VuforiaBehaviour.Instance.World;
    }
}
