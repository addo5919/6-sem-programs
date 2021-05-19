import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JPasswordField;
import javax.swing.JCheckBox;

public class LoginScreen {

	private JFrame frame;
	private JTextField txtUn;
	String username="Aditya";
	String password="12345";
	private JPasswordField txtPass;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					LoginScreen window = new LoginScreen();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public LoginScreen() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 742, 306);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Username");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 26));
		lblNewLabel.setBounds(122, 58, 147, 41);
		frame.getContentPane().add(lblNewLabel);
		
		JLabel lblPassword = new JLabel("Password");
		lblPassword.setFont(new Font("Tahoma", Font.BOLD, 26));
		lblPassword.setBounds(122, 122, 147, 41);
		frame.getContentPane().add(lblPassword);
		
		txtUn = new JTextField();
		txtUn.setFont(new Font("Tahoma", Font.PLAIN, 20));
		txtUn.setBounds(290, 58, 211, 40);
		frame.getContentPane().add(txtUn);
		txtUn.setColumns(10);
		
		JButton btnLogin = new JButton("Login");
		btnLogin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				String un=txtUn.getText();
				String pass=txtPass.getText();
				
				if(un.equals(username) && pass.equals(password))
				{
					JOptionPane.showMessageDialog(null,"Login successful");
					StudentDBMS obj=new StudentDBMS();
					obj.frame.setVisible(true);
				}
				else
				{
				 JOptionPane.showMessageDialog(null,"Invalid username or password!");
				}
				
				
				
			}
		});
		btnLogin.setFont(new Font("Tahoma", Font.BOLD, 26));
		btnLogin.setBounds(318, 218, 138, 41);
		frame.getContentPane().add(btnLogin);
		
		txtPass = new JPasswordField();
		txtPass.setFont(new Font("Tahoma", Font.PLAIN, 20));
		txtPass.setBounds(290, 122, 211, 41);
		frame.getContentPane().add(txtPass);
		
		JCheckBox jcbshow = new JCheckBox("Show password");
		jcbshow.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(jcbshow.isSelected())
				{
				 txtPass.setEchoChar((char)0);
				}
				else
				{
				 txtPass.setEchoChar('*');
				}
			}
		});
		jcbshow.setFont(new Font("Tahoma", Font.PLAIN, 20));
		jcbshow.setBounds(290, 169, 166, 43);
		frame.getContentPane().add(jcbshow);
	}
}
