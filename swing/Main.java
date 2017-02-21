public class Main
{
    /** This class displays the window and starts the connection to the server */
    public static void main(String argv[])
    {
        RemoteControl.displayWindow();
        Client.connect(argv);
    }
}
