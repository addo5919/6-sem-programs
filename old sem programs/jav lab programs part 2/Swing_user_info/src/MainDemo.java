import javax.swing.*;
import javax.swing.event.*;
import java.awt.*;
import java.awt.event.*;

public class MainDemo implements ActionListener,ListSelectionListener {
	JFrame jfrm;
	JList list;
	String cities[]= {"Banglore","New York","Manchester","Dubai","Tokyo"};
	JScrollPane jsp;
	JTextField jtf1,jtf2;
	JRadioButton jrb1,jrb2;
	JCheckBox jcb1,jcb2,jcb3,jcb4,jcb5;
	JButton jb;
	
	 JLabel jlab1;
	 JLabel jlab2;
	 JLabel jlab3;
	 JLabel jlab4;
	 JLabel jlab5;
	
	
	
	MainDemo()
	{
	 jfrm=new JFrame("User details");
	 jfrm.setSize(375,150);
     jfrm.setLayout(new FlowLayout());
	 jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	 
	 jlab1=new JLabel("Select a city");
	 jlab2=new JLabel("Name:");
	 jlab3=new JLabel("Phone:");
	 jlab4=new JLabel("Select gender:");
	 jlab5=new JLabel("Select your hobbies:");
	 
	 list=new JList(cities);
	 list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
	 list.addListSelectionListener(this);
	 jsp=new JScrollPane(list);
	 
	 jfrm.add(jlab1);
	 jfrm.add(jsp);	  //adding list(cities)

	 jfrm.add(jlab2);
	 jtf1=new JTextField(15);
	 jtf2=new JTextField(15);  //adding text fields(name,phone)
	 jfrm.add(jtf1);
	 jfrm.add(jlab3);
	 jfrm.add(jtf2);
	 
	 jrb1=new JRadioButton("Male");
	 jrb2=new JRadioButton("Female");
	 ButtonGroup bg=new ButtonGroup(); //adding radio buttons(gender)
	 bg.add(jrb1);
	 bg.add(jrb2);
	 jfrm.add(jlab4);
	 jfrm.add(jrb1);
	 jfrm.add(jrb2);
	 
	 jfrm.add(jlab5);
	 jcb1=new JCheckBox("Singing");
	 jfrm.add(jcb1);
	 jcb2=new JCheckBox("Dancing");
	 jfrm.add(jcb2);
	 jcb3=new JCheckBox("Reading");
	 jfrm.add(jcb3);
	 jcb4=new JCheckBox("Sports");
	 jfrm.add(jcb4);
	 jcb5=new JCheckBox("Gaming"); //adding checkboxes(hobbies)
	 jfrm.add(jcb5);
	 
	 
	 jb=new JButton("Submit");
	 jfrm.add(jb);
	 jb.addActionListener(this);
	 
	 jfrm.setVisible(true);
	}
	
	public void actionPerformed(ActionEvent ae) 
	{
     String city;
     int i=list.getSelectedIndex();
     city=cities[i];
     
     String name=jtf1.getText();
     String phone=jtf2.getText();
     
     String gender;
     if(jrb1.isSelected())
    	 gender=jrb1.getActionCommand();
     else
    	 gender=jrb2.getActionCommand();
     
     String hobbies="";
     if(jcb1.isSelected())
     {
    	 hobbies+=jcb1.getActionCommand();
         hobbies+=" ";
     }
     if(jcb2.isSelected())
     {
    	 hobbies+=jcb2.getActionCommand();
         hobbies+=" ";
     }
     if(jcb3.isSelected())
     {
    	 hobbies+=jcb3.getActionCommand();
         hobbies+=" ";
     }
     if(jcb4.isSelected())
     {
    	 hobbies+=jcb4.getActionCommand();
         hobbies+=" ";
     }
     if(jcb5.isSelected())
     {
    	 hobbies+=jcb5.getActionCommand();
         hobbies+=" ";
     }
		
     JOptionPane.showMessageDialog(jfrm,"City:"+city+"\nName:"+name+"\nPhone no:"+phone+"\nGender:"+gender+"\nHobbies:"+hobbies);
	}
	
	public void valueChanged(ListSelectionEvent le) //method to display name of selected city in list selection
	{
		int i=list.getSelectedIndex();
		 if(i==-1)
	      jlab1.setText("Select a city");
		 else
		  jlab1.setText(cities[i]);
	}
	
	

	public static void main(String[] args) {
	 SwingUtilities.invokeLater(new Runnable() {
		 public void run()
		 {
		  new MainDemo();
		 }
	 });
	

	}

}
