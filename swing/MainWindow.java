import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.event.*;

class MainWindow extends JFrame
{
    private JTextArea textArea;
    private JButton button1;
    private JButton button2;
    private JButton button3;
    private static final long serialVersionUID = 1L;

    public static void main(String[] argv)
    {
        new MainWindow();
    }

    public MainWindow()
    {
        textArea = new JTextArea(4,1);
        button1 = new JButton("Add text 1");
        button2 = new JButton("Add text 2");
        button3 = new JButton("Close");
        JScrollPane scrollPane = new JScrollPane(textArea);
        button1.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                textArea.append("text1\n");
            }
        });
        button2.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                textArea.append("text2\n");
            }
        });
        button3.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });
        JPanel panel = new JPanel();
        panel.add(button1);
        panel.add(button2);
        panel.add(button3);
        add(panel,BorderLayout.SOUTH);
        add(scrollPane,BorderLayout.CENTER);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }
}
