/*===============================================================================
Copyright (c) 2021 PTC Inc. All Rights Reserved.

Confidential and Proprietary - Protected under copyright and other laws.
Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.
===============================================================================*/

using UnityEngine;
using System.Collections;

public class AsyncSceneLoader : MonoBehaviour
{
    public float LoadingDelay = 2.0f;
   
    void Start()
    {
        StartCoroutine(LoadNextSceneAfter(LoadingDelay));
    }
    
    IEnumerator LoadNextSceneAfter(float seconds)
    {
        yield return new WaitForSeconds(seconds);

        UnityEngine.SceneManagement.SceneManager.LoadScene(UnityEngine.SceneManagement.SceneManager.GetActiveScene().buildIndex + 1);
    }
}
