import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.BevelBorder;
import javax.swing.border.LineBorder;
import java.awt.Color;
import javax.swing.JButton;
import java.awt.Font;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import javax.swing.JScrollPane;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JComboBox;
import javax.swing.DefaultComboBoxModel;
import java.awt.SystemColor;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

import javax.swing.*;
import java.sql.*;
import javax.swing.table.DefaultTableModel;
import java.text.DateFormat;
import java.text.MessageFormat;
import java.text.SimpleDateFormat;
import java.util.Vector;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.print.PrinterException;

public class StudentDBMS {
    
	static String url="jdbc:sqlserver://MSI\\MSSQLSERVER;"+"databaseName=master;integratedSecurity=true;";
	static Connection link;
	static PreparedStatement pst;
	static ResultSet results;
	
	
	
	/*private*/ JFrame frame;
	private JTable table;
	private JTextField txtStudentID;
	private JTextField txtFirstname;
	private JTextField txtSurname;
	private JTextField txtAddress;
	private JTextField txtMobile;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					StudentDBMS window = new StudentDBMS();
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
	public StudentDBMS() {
		initialize();
		updateDB();
	}
	
	//=======================function declaration==================================================================================================================================
	void updateDB()  //used to display database contents in jtable of java application
	{
	 //int q
	 try
	 {
		//load the database driver
	 Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
	//establish connection to the database
	 link=DriverManager.getConnection(url);
	 pst=link.prepareStatement("select * from studentdata");
	 results=pst.executeQuery();
	 
	// ResultSetMetaData rsmd=results.getMetaData(); //getting meta data of resultset object in order to get column count
	// q=rsmd.getColumnCount();
	 DefaultTableModel dtm=(DefaultTableModel)table.getModel(); //obtaining data displayed by JTable
	 dtm.setRowCount(0); //deleting all rows from JTable as we are again going to add rows from the database and display on JTable
	 
	 while(results.next())
	 {
	   Vector v=new Vector();
	   v.add(results.getInt("id"));
	   v.add(results.getInt("studentid"));
	   v.add(results.getString("firstname"));
	   v.add(results.getString("surname"));
	   v.add(results.getString("address"));
	   v.add(results.getString("gender"));
	   v.add(results.getString("mobile"));
	   v.add(results.getString("maths"));
	   v.add(results.getString("games"));
	   v.add(results.getString("datasci"));
	   v.add(results.getString("analysis"));
	   v.add(results.getString("graphic"));
	   v.add(results.getString("data_base"));
	   v.add(results.getString("science"));
	   v.add(results.getString("english"));
	   
	   dtm.addRow(v); // add row to JTable
	 }
	 
	 
	 }catch(Exception e)
	 {
	 JOptionPane.showMessageDialog(null,e);
	 }
	}
	
	
	//=============================================================================================================================================================================

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(SystemColor.activeCaption);
		frame.setBackground(Color.WHITE);
		frame.setBounds(100, 100, 1500, 800);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JPanel panel = new JPanel();
		panel.setBackground(SystemColor.activeCaption);
		panel.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		panel.setBounds(10, 10, 1466, 86);
		frame.getContentPane().add(panel);
		panel.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Student Database Management System");
		lblNewLabel.setFont(new Font("Tahoma", Font.BOLD, 55));
		lblNewLabel.setBounds(216, 10, 1207, 66);
		panel.add(lblNewLabel);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBackground(SystemColor.activeCaption);
		panel_1.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		panel_1.setBounds(10, 106, 1466, 647);
		frame.getContentPane().add(panel_1);
		panel_1.setLayout(null);
		
		JPanel panel_2 = new JPanel();
		panel_2.setBackground(SystemColor.activeCaption);
		panel_2.setBorder(new LineBorder(Color.BLUE, 4));
		panel_2.setBounds(10, 10, 551, 512);
		panel_1.add(panel_2);
		panel_2.setLayout(null);
		
		JLabel lblStudentID = new JLabel("Student ID");
		lblStudentID.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblStudentID.setBounds(25, 28, 118, 37);
		panel_2.add(lblStudentID);
		
		txtStudentID = new JTextField();
		txtStudentID.setFont(new Font("Tahoma", Font.BOLD, 20));
		txtStudentID.setBounds(159, 28, 382, 37);
		panel_2.add(txtStudentID);
		txtStudentID.setColumns(10);
		
		JComboBox cboGender = new JComboBox();
		cboGender.setModel(new DefaultComboBoxModel(new String[] {"", "Male", "Female"}));
		cboGender.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboGender.setBounds(159, 246, 111, 37);
		panel_2.add(cboGender);
		
		JLabel lblFirstname = new JLabel("Firstname");
		lblFirstname.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblFirstname.setBounds(25, 81, 118, 37);
		panel_2.add(lblFirstname);
		
		txtFirstname = new JTextField();
		txtFirstname.setFont(new Font("Tahoma", Font.BOLD, 20));
		txtFirstname.setColumns(10);
		txtFirstname.setBounds(159, 81, 382, 37);
		panel_2.add(txtFirstname);
		
		JLabel lblSurname = new JLabel("Surname");
		lblSurname.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblSurname.setBounds(25, 135, 118, 37);
		panel_2.add(lblSurname);
		
		txtSurname = new JTextField();
		txtSurname.setFont(new Font("Tahoma", Font.BOLD, 20));
		txtSurname.setColumns(10);
		txtSurname.setBounds(159, 135, 382, 37);
		panel_2.add(txtSurname);
		
		JLabel lblAddress = new JLabel("Address");
		lblAddress.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblAddress.setBounds(25, 189, 118, 37);
		panel_2.add(lblAddress);
		
		txtAddress = new JTextField();
		txtAddress.setFont(new Font("Tahoma", Font.BOLD, 20));
		txtAddress.setColumns(10);
		txtAddress.setBounds(159, 189, 382, 37);
		panel_2.add(txtAddress);
		
		txtMobile = new JTextField();
		txtMobile.setFont(new Font("Tahoma", Font.BOLD, 20));
		txtMobile.setColumns(10);
		txtMobile.setBounds(408, 246, 133, 37);
		panel_2.add(txtMobile);
		
		JLabel lblMobile = new JLabel("Mobile");
		lblMobile.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblMobile.setBounds(300, 246, 100, 37);
		panel_2.add(lblMobile);
		
		JLabel lblGender = new JLabel("Gender");
		lblGender.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblGender.setBounds(25, 246, 118, 37);
		panel_2.add(lblGender);
		
		JPanel panel_3 = new JPanel();
		panel_3.setBackground(SystemColor.activeCaption);
		panel_3.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		panel_3.setBounds(10, 293, 260, 209);
		panel_2.add(panel_3);
		panel_3.setLayout(null);
		
		JLabel lblMaths = new JLabel("Maths");
		lblMaths.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblMaths.setBounds(10, 10, 118, 37);
		panel_3.add(lblMaths);
		
		JComboBox cboMaths = new JComboBox();
		cboMaths.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit ", "Complete"}));
		cboMaths.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboMaths.setBounds(130, 10, 125, 37);
		panel_3.add(cboMaths);
		
		JLabel lblGames = new JLabel("Games");
		lblGames.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblGames.setBounds(10, 64, 118, 37);
		panel_3.add(lblGames);
		
		JComboBox cboGames = new JComboBox();
		cboGames.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit", "Complete"}));
		cboGames.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboGames.setBounds(130, 64, 125, 37);
		panel_3.add(cboGames);
		
		JLabel lblDataSci = new JLabel("Data Sci");
		lblDataSci.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblDataSci.setBounds(10, 111, 118, 37);
		panel_3.add(lblDataSci);
		
		JComboBox cboDataSci = new JComboBox();
		cboDataSci.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit", "Complete"}));
		cboDataSci.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboDataSci.setBounds(130, 111, 125, 37);
		panel_3.add(cboDataSci);
		
		JLabel lblAnalysis = new JLabel("Analysis");
		lblAnalysis.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblAnalysis.setBounds(10, 162, 118, 37);
		panel_3.add(lblAnalysis);
		
		JComboBox cboAnalysis = new JComboBox();
		cboAnalysis.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit ", "Complete"}));
		cboAnalysis.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboAnalysis.setBounds(130, 162, 125, 37);
		panel_3.add(cboAnalysis);
		
		JPanel panel_3_1 = new JPanel();
		panel_3_1.setBackground(SystemColor.activeCaption);
		panel_3_1.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
		panel_3_1.setBounds(280, 293, 261, 209);
		panel_2.add(panel_3_1);
		panel_3_1.setLayout(null);
		
		JLabel lblGraphic = new JLabel("Graphic");
		lblGraphic.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblGraphic.setBounds(10, 10, 118, 37);
		panel_3_1.add(lblGraphic);
		
		JComboBox cboGraphic = new JComboBox();
		cboGraphic.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit", "Complete"}));
		cboGraphic.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboGraphic.setBounds(132, 10, 123, 37);
		panel_3_1.add(cboGraphic);
		
		JLabel lblDatabase = new JLabel("Database");
		lblDatabase.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblDatabase.setBounds(10, 62, 118, 37);
		panel_3_1.add(lblDatabase);
		
		JComboBox cboDatabase = new JComboBox();
		cboDatabase.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit", "Complete"}));
		cboDatabase.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboDatabase.setBounds(132, 62, 123, 37);
		panel_3_1.add(cboDatabase);
		
		JLabel lblScience = new JLabel("Science");
		lblScience.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblScience.setBounds(10, 109, 118, 37);
		panel_3_1.add(lblScience);
		
		JComboBox cboScience = new JComboBox();
		cboScience.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit", "Complete"}));
		cboScience.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboScience.setBounds(132, 109, 123, 37);
		panel_3_1.add(cboScience);
		
		JLabel lblEnglish = new JLabel("English");
		lblEnglish.setFont(new Font("Tahoma", Font.BOLD, 20));
		lblEnglish.setBounds(10, 162, 118, 37);
		panel_3_1.add(lblEnglish);
		
		JComboBox cboEnglish = new JComboBox();
		cboEnglish.setModel(new DefaultComboBoxModel(new String[] {"No", "Yes", "Core Unit", "Complete"}));
		cboEnglish.setFont(new Font("Tahoma", Font.BOLD, 20));
		cboEnglish.setBounds(132, 162, 123, 37);
		panel_3_1.add(cboEnglish);
		
		JPanel panel_2_1 = new JPanel();
		panel_2_1.setBackground(SystemColor.activeCaption);
		panel_2_1.setBorder(new LineBorder(Color.BLUE, 4));
		panel_2_1.setBounds(571, 10, 885, 512);
		panel_1.add(panel_2_1);
		panel_2_1.setLayout(null);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 10, 865, 492);
		panel_2_1.add(scrollPane);
		
		table = new JTable();
		table.addMouseListener(new MouseAdapter() {  //when a row of jtable is clicked then that rows details will appear on corresponding textfields and comboboxes
			@Override
			public void mouseClicked(MouseEvent e) {
				DefaultTableModel dtm=(DefaultTableModel)table.getModel();
				int selectedrow=table.getSelectedRow();
				
				txtStudentID.setText(dtm.getValueAt(selectedrow,1).toString());
				txtFirstname.setText(dtm.getValueAt(selectedrow,2).toString());
				txtSurname.setText(dtm.getValueAt(selectedrow,3).toString());
				txtAddress.setText(dtm.getValueAt(selectedrow,4).toString());
				cboGender.setSelectedItem(dtm.getValueAt(selectedrow,5).toString());
				txtMobile.setText(dtm.getValueAt(selectedrow,6).toString());
				cboMaths.setSelectedItem(dtm.getValueAt(selectedrow,7).toString());
				cboGames.setSelectedItem(dtm.getValueAt(selectedrow,8).toString());
				cboDataSci.setSelectedItem(dtm.getValueAt(selectedrow,9).toString());
				cboAnalysis.setSelectedItem(dtm.getValueAt(selectedrow,10).toString());
				cboGraphic.setSelectedItem(dtm.getValueAt(selectedrow,11).toString());
				cboDatabase.setSelectedItem(dtm.getValueAt(selectedrow,12).toString());
				cboScience.setSelectedItem(dtm.getValueAt(selectedrow,13).toString());
				cboEnglish.setSelectedItem(dtm.getValueAt(selectedrow,14).toString());
				
			}
		});
		table.setBackground(SystemColor.activeCaption);
		scrollPane.setViewportView(table);
		table.setModel(new DefaultTableModel(
			new Object[][] {
			},
			new String[] {
				"ID", "Student ID", "Firstname", "Surname", "Address", "Gender", "Mobile", "Maths", "Games", "Data Sci", "Analysis", "Graphic", "Database", "Science", "English"
			}
		) {
			Class[] columnTypes = new Class[] {
				Integer.class, Integer.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class, String.class
			};
			public Class getColumnClass(int columnIndex) {
				return columnTypes[columnIndex];
			}
		});
		
		JPanel panel_2_1_1 = new JPanel();
		panel_2_1_1.setBackground(SystemColor.activeCaption);
		panel_2_1_1.setBounds(10, 532, 1446, 105);
		panel_1.add(panel_2_1_1);
		panel_2_1_1.setBorder(new LineBorder(Color.BLUE, 4));
		panel_2_1_1.setLayout(null);
		
		JButton btnExit=new JButton("Exit");
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				int val=JOptionPane.showConfirmDialog(null, "Are u sure u want to Exit?", "Student DBMS", JOptionPane.YES_NO_OPTION);
				if(val==0)
				System.exit(0);
			}
		});
		btnExit.setFont(new Font("Tahoma", Font.BOLD, 36));
		btnExit.setBounds(1211, 10, 225, 78);
		panel_2_1_1.add(btnExit);
		
		JButton btnDelete = new JButton("Delete");
		btnDelete.addActionListener(new ActionListener() {  //to delete a row
			public void actionPerformed(ActionEvent e) {
				DefaultTableModel dtm=(DefaultTableModel)table.getModel();
				int selectedrow=table.getSelectedRow();
				int id=Integer.parseInt(dtm.getValueAt(selectedrow,0).toString());
				
				 
				try
				{   int val=JOptionPane.showConfirmDialog(null,"Are u sure u want to delete this record?","Student DBMS",JOptionPane.YES_NO_OPTION);
					if(val==0) //if user presses 'yes' in confirmation dialog box
					{
					//load the database driver
				 Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
				//establish connection to the database
				 link=DriverManager.getConnection(url);
				 pst=link.prepareStatement("delete from studentdata"+" where id=?");
				 
				 pst.setInt(1,id);
				 
				 pst.executeUpdate();
				 JOptionPane.showMessageDialog(null,"Student Record deleted successfully");
				 
				 txtStudentID.setText("");
				 txtStudentID.requestFocus(); //places focus(pointer) on StudentID textfield after delete operation so we can immediately start writing
				 txtFirstname.setText("");
				 txtSurname.setText("");
				 txtAddress.setText("");
				 cboGender.setSelectedIndex(0);
				 txtMobile.setText("");
				 cboMaths.setSelectedIndex(0);
				 cboGames.setSelectedIndex(0);
				 cboDataSci.setSelectedIndex(0);
				 cboAnalysis.setSelectedIndex(0);
				 cboGraphic.setSelectedIndex(0);
				 cboDatabase.setSelectedIndex(0);
				 cboScience.setSelectedIndex(0);
				 cboEnglish.setSelectedIndex(0);
				 
				 updateDB();
					}
				 
				}catch(ClassNotFoundException cnfexc)
				{
				 System.out.println("Unable to load the database driver");
				}
				catch(SQLException sqlexc)
				{
				 System.out.println("Unable to connect to database");
				}
				
				
			}
		});
		btnDelete.setFont(new Font("Tahoma", Font.BOLD, 36));
		btnDelete.setBounds(977, 10, 225, 78);
		panel_2_1_1.add(btnDelete);
		
		JButton btnReset = new JButton("Reset");
		btnReset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {  //making all textfields and comboboxes empty or back to default and also JTable is made empty
				
				 txtStudentID.setText("");
				 txtFirstname.setText("");
				 txtSurname.setText("");
				 txtAddress.setText("");
				 cboGender.setSelectedIndex(0);
				 txtMobile.setText("");
				 cboMaths.setSelectedIndex(0);
				 cboGames.setSelectedIndex(0);
				 cboDataSci.setSelectedIndex(0);
				 cboAnalysis.setSelectedIndex(0);
				 cboGraphic.setSelectedIndex(0);
				 cboDatabase.setSelectedIndex(0);
				 cboScience.setSelectedIndex(0);
				 cboEnglish.setSelectedIndex(0);
				 
				 DefaultTableModel dtm=(DefaultTableModel)table.getModel();
				 dtm.setRowCount(0);
				 
			}
		});
		btnReset.setFont(new Font("Tahoma", Font.BOLD, 36));
		btnReset.setBounds(742, 10, 225, 78);
		panel_2_1_1.add(btnReset);
		
		JButton btnUpdate = new JButton("Update");
		btnUpdate.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				DefaultTableModel dtm=(DefaultTableModel)table.getModel();
				int selectedrow=table.getSelectedRow();
				int id=Integer.parseInt(dtm.getValueAt(selectedrow,0).toString());
				
				try
				{
					//load the database driver
				 Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
				//establish connection to the database
				 link=DriverManager.getConnection(url);
				 pst=link.prepareStatement("update studentdata"+" set studentid=?,firstname=?,surname=?,address=?,gender=?,"
				 		+ "mobile=?,maths=?,games=?,datasci=?,analysis=?,graphic=?,data_base=?,science=?,english=?"+" where id=?");
				 pst.setInt(1,Integer.parseInt(txtStudentID.getText()));
				 pst.setString(2,txtFirstname.getText());
				 
				 if(txtSurname.getText().equals(""))
					 pst.setString(3,null);
				 else
				 pst.setString(3,txtSurname.getText());
				 
				 pst.setString(4,txtAddress.getText());
				 
				 if(cboGender.getSelectedItem().toString().equals(""))
					 pst.setString(5,null);
				 else
				 pst.setString(5,(String)cboGender.getSelectedItem());
				 
				 pst.setString(6,txtMobile.getText());
				 pst.setString(7,(String)cboMaths.getSelectedItem());
				 pst.setString(8,(String)cboGames.getSelectedItem());
				 pst.setString(9,(String)cboDataSci.getSelectedItem());
				 pst.setString(10,(String)cboAnalysis.getSelectedItem());
				 pst.setString(11,(String)cboGraphic.getSelectedItem());
				 pst.setString(12,(String)cboDatabase.getSelectedItem());
				 pst.setString(13,(String)cboScience.getSelectedItem());
				 pst.setString(14,(String)cboEnglish.getSelectedItem());
				 pst.setInt(15,id);
				 
				 pst.executeUpdate();
				 JOptionPane.showMessageDialog(null,"Student Record updated successfully");
				 updateDB();
				 
				}catch(ClassNotFoundException cnfexc)
				{
				 System.out.println("Unable to load the database driver");
				}
				catch(SQLException sqlexc)
				{
				 System.out.println("Unable to connect to database");
				}
				
			}
		});
		btnUpdate.setFont(new Font("Tahoma", Font.BOLD, 36));
		btnUpdate.setBounds(507, 10, 225, 78);
		panel_2_1_1.add(btnUpdate);
		
		JButton btnPrint = new JButton("Print");
		btnPrint.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				MessageFormat header=new MessageFormat("studentdata Table");
				MessageFormat footer=new MessageFormat("-{0}-"); //causes page numbers to show up on printed pages and increments automatically. starts with -1- on first page
				
				try
				{
				 table.print(JTable.PrintMode.NORMAL,header,footer); //in NORMAL print mode, if many columns are there then they will be printed on different page
				}catch(PrinterException pe)                          //in FIT_WIDTH print mode,if many cols are there then their size will be reduced so that
				{                                                   //they fit on the same page.
				  JOptionPane.showMessageDialog(null,"Something went wrong while printing");                     
				}
			}                                                                     
		});
		btnPrint.setFont(new Font("Tahoma", Font.BOLD, 36));
		btnPrint.setBounds(272, 10, 225, 78);
		panel_2_1_1.add(btnPrint);
		
		JButton btnAddNew = new JButton("Add New");
		btnAddNew.addActionListener(new ActionListener() { //adding new row to the studentdata database
			public void actionPerformed(ActionEvent e) {
				try
				{
					//load the database driver
				 Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
				//establish connection to the database
				 link=DriverManager.getConnection(url);
				 pst=link.prepareStatement("insert into studentdata(studentid,firstname,surname,address,gender,mobile,maths,games,datasci,analysis,graphic,data_base,science,english)"
				 		+ " values(?,?,?,?,?,?,?,?,?,?,?,?,?,?) ");
				 pst.setInt(1,Integer.parseInt(txtStudentID.getText()));
				 pst.setString(2,txtFirstname.getText());
				 
				 if(txtSurname.getText().equals(""))
					 pst.setString(3,null);
				 else
				 pst.setString(3,txtSurname.getText());
				 
				 pst.setString(4,txtAddress.getText());
				 
				 if(cboGender.getSelectedItem().toString().equals(""))
					 pst.setString(5,null);
				 else
				 pst.setString(5,(String)cboGender.getSelectedItem());
				 
				 pst.setString(6,txtMobile.getText());
				 pst.setString(7,(String)cboMaths.getSelectedItem());
				 pst.setString(8,(String)cboGames.getSelectedItem());
				 pst.setString(9,(String)cboDataSci.getSelectedItem());
				 pst.setString(10,(String)cboAnalysis.getSelectedItem());
				 pst.setString(11,(String)cboGraphic.getSelectedItem());
				 pst.setString(12,(String)cboDatabase.getSelectedItem());
				 pst.setString(13,(String)cboScience.getSelectedItem());
				 pst.setString(14,(String)cboEnglish.getSelectedItem());
				 
				 pst.executeUpdate();
				 JOptionPane.showMessageDialog(null,"Student Record added successfully");
				 updateDB();
				 
				}catch(ClassNotFoundException cnfexc)
				{
				 System.out.println("Unable to load the database driver");
				}
				catch(SQLException sqlexc)
				{
				 System.out.println("Unable to connect to database");
				}
				
			}
		});
		btnAddNew.setFont(new Font("Tahoma", Font.BOLD, 36));
		btnAddNew.setBounds(22, 10, 225, 78);
		panel_2_1_1.add(btnAddNew);
	}
}
