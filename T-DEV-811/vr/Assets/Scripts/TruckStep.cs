public class TruckStep
{
    public Trash trash;
    public WS_Client wsClient;
    public MapManager mapManager;
    public int trashID;

    public void Validate()
    {
        trash.SetStatus(trash.isOpen, false, trash.isTilted, true);
        wsClient.SendData(new Data(trash.id, trash.isOpen, false, trash.isTilted).ToJson());
    }
}