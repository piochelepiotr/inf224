import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;

public class RemoteControl
{
    private static final long serialVersionUID = 1L;

    /** The input to type the names of medias */
	private static JTextArea textArea;
	
	/** panel to display results of requests */
	private static JLabel results;

	/** return the name of the media*/
	public static String getInputText(){
		return textArea.getText();
	}
	
	/** display content on the label*/
	public static void display(String result){
		results.setText(result);
    }

    /** open the window to control the server */
    public static void displayWindow()
    {
        JFrame frame = new JFrame("Remote control");
        //Listener to quit the program when the window is closed
        frame.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
        	}
        });

        textArea = new JTextArea(3,60);
        results = new JLabel();

        SearchAction searchAction = new SearchAction("Search");
        PlayAction playAction = new PlayAction("Play");
        CloseAction closeAction = new CloseAction("Close");

        JButton searchButton = new JButton(searchAction);
        JButton playButton = new JButton(playAction);
        JButton closeButton = new JButton(closeAction);

        JScrollPane scrollPane = new JScrollPane(textArea);
        JPanel panel = new JPanel();

        // Create the menu bar
        JMenuBar menuBar= new JMenuBar();
        JMenu menu = new JMenu("Menu");
        
        menu.add(new JMenuItem(playAction));
        menu.add(new JMenuItem(searchAction));
        menu.add(new JMenuItem(closeAction));
        
        menuBar.add(new JMenuItem(playAction));
        menuBar.add(new JMenuItem(searchAction));
        menuBar.add(new JMenuItem(closeAction));

        menuBar.add(menu);

        frame.setJMenuBar(menuBar);

        panel.add(searchButton);
        panel.add(playButton);
        panel.add(closeButton);
        frame.add(panel,BorderLayout.EAST);
        frame.add(scrollPane,BorderLayout.CENTER);
        frame.add(results,BorderLayout.SOUTH);
        frame.pack();
        frame.setVisible(true);
    }
}

/**
 * Action to send a Search request to the server
 */
class SearchAction extends AbstractAction {

	private static final long serialVersionUID = 675765L;

	public SearchAction(String name) {
		super(name);
	}

	@Override
	public void actionPerformed(ActionEvent e)
    {
        String response = Client.send("display/"+RemoteControl.getInputText());
		RemoteControl.display("Search results: "+ response);
		
	}
	
}

/**
 * Action to send a Play request to the server
 */
class PlayAction extends AbstractAction {

	private static final long serialVersionUID = 98669L;

	public PlayAction(String name) {
		super(name);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
	    Client.send("play/"+RemoteControl.getInputText());
	}
	
}

/**
 * Action to quit the applet
 */
class CloseAction extends AbstractAction {

	private static final long serialVersionUID = 970007L;

	public CloseAction(String name) {
		super(name);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		System.exit(0);
		
	}
	
}
