using System;
using UnityEngine;

[Serializable]
public struct Data
{
    public int id;
    public bool isOpen;
    public bool isFilled;
    public bool isTilted;

    public Data(string data)
    {
        Data d = JsonUtility.FromJson<Data>(data);
        id = d.id;
        isOpen = d.isOpen;
        isFilled = d.isFilled;
        isTilted = d.isTilted;
    }

    public Data(int id, bool isOpen, bool isFilled, bool isTilted)
    {
        this.id = id;
        this.isOpen = isOpen;
        this.isFilled = isFilled;
        this.isTilted = isTilted;
    }

    public readonly string ToJson()
    {
        return "{\"id\":" + id + ",\"isOpen\":" + isOpen + ",\"isFilled\":" + isFilled + ",\"isTilted\":" + isTilted + "}";
    }
}