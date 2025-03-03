/*===============================================================================
Copyright (c) 2015-2018 PTC Inc. All Rights Reserved.

Copyright (c) 2015 Qualcomm Connected Experiences, Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/
using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using UnityEngine.SceneManagement;

public class LoadingScreen : MonoBehaviour
{
    RawImage mSpinnerImage;
    AsyncOperation mAsyncOperation;
    bool mSceneReadyToActivate;

    public static string SceneToLoad { get; set; }

    public static void Run()
    {
        SceneManager.LoadSceneAsync("2-Loading");
    }

    void Start()
    {
        mSpinnerImage = GetComponentInChildren<RawImage>();
        Application.backgroundLoadingPriority = ThreadPriority.Low;
        StartCoroutine(LoadNextSceneAsync());
    }

    void Update()
    {
        if (mSpinnerImage)
        {
            if (!mSceneReadyToActivate)
                mSpinnerImage.rectTransform.Rotate(Vector3.forward, 90.0f * Time.deltaTime);
            else
                mSpinnerImage.enabled = false;
        }

        if (mAsyncOperation != null)
        {
            if (mAsyncOperation.progress < 0.9f)
                Debug.Log("Scene Loading Progress: " + mAsyncOperation.progress * 100 + "%");
            else
            {
                mSceneReadyToActivate = true;
                mAsyncOperation.allowSceneActivation = true;
            }
        }
    }
    
    IEnumerator LoadNextSceneAsync()
    {
        var nextSceneIndex = SceneManager.GetActiveScene().buildIndex + 1;

        if (string.IsNullOrEmpty(SceneToLoad))
            mAsyncOperation = SceneManager.LoadSceneAsync(nextSceneIndex);
        else
            mAsyncOperation = SceneManager.LoadSceneAsync(SceneToLoad);

        mAsyncOperation.allowSceneActivation = false;

        yield return mAsyncOperation;
    }
}
