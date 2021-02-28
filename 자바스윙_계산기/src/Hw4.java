

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.Rectangle2D;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

class Hw4Button extends JButton{
	String str;
	Hw4Button(String s){
		super(s);
		str = s;
	}
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		Color color1 = new Color(0xe5dedb);
		g.setColor(color1);
		g.fillRoundRect(10, 10, this.getWidth()-20, this.getHeight()-20,20,20);
		
		setFont(new Font("Arial", Font.BOLD, 50));
		Color color2 = new Color(0x816558);
		g.setColor(color2);
		g.drawString(str, this.getWidth()/2 -15, this.getHeight()/2 + 15);	
	}
	
}

class Hw4Label extends JPanel {
	JLabel label;
	
	Hw4Label(){
		super();
		label = new JLabel("0");
		label.setFont(new Font("Arial", Font.PLAIN, 80));
	}
	
	
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		Graphics2D g2 = (Graphics2D) g ;
		GradientPaint gp = new GradientPaint(0,0,new Color(0xc0c0c0),0,this.getHeight(),new Color(0x060606));
		g2.setPaint(gp);
		g2.fill(new Rectangle2D.Float(0,0,this.getWidth(), this.getHeight()));
		GradientPaint gp2 = new GradientPaint(0,0,new Color(0x5d5f40),0,this.getHeight(),new Color(0xe0e0e0));
		g2.setPaint(gp2);
		g2.fill(new Rectangle2D.Float(10, 10, this.getWidth()-20, this.getHeight()-20));
		
		add(label);
	}
}

class Hw4Panel extends JPanel implements ActionListener{
	
	JLabel label;
	Hw4Button but7 = new Hw4Button("7");
	Hw4Button but8 = new Hw4Button("8");
	Hw4Button but9 = new Hw4Button("9");
	Hw4Button butc = new Hw4Button("C");
	Hw4Button but4 = new Hw4Button("4");
	Hw4Button but5 = new Hw4Button("5");
	Hw4Button but6 = new Hw4Button("6");
	Hw4Button but_add = new Hw4Button("+");
	Hw4Button but1 = new Hw4Button("1");
	Hw4Button but2 = new Hw4Button("2");
	Hw4Button but3 = new Hw4Button("3");
	Hw4Button but_sub = new Hw4Button("-");
	Hw4Button but0 = new Hw4Button("0");
	JButton butx1 = new JButton();
	JButton butx2 = new JButton();
	Hw4Button but_equal = new Hw4Button("=");
	
	
		
	Hw4Panel(Hw4Label L){

		label = L.label;
		setLayout(new GridLayout(4,4,1,1));
		add(but7);
		add(but8);
		add(but9);
		add(butc);
		add(but4);
		add(but5);
		add(but6);
		add(but_add);
		add(but1);
		add(but2);
		add(but3);
		add(but_sub);
		add(but0);
		add(butx1);
		add(butx2);
		add(but_equal);
		but7.addActionListener(this);
		but8.addActionListener(this);
		but9.addActionListener(this);
		butc.addActionListener(this);
		but4.addActionListener(this);
		but5.addActionListener(this);
		but6.addActionListener(this);
		but_add.addActionListener(this);
		but1.addActionListener(this);
		but2.addActionListener(this);
		but3.addActionListener(this);
		but_sub.addActionListener(this);
		but0.addActionListener(this);
		but_equal.addActionListener(this);
		
	}
	
	int num;
	int addc=1, subc=0, sum = 0;
	String n = "0";
	@Override
	public void actionPerformed(ActionEvent e) {
		Object source = e.getSource();
		if(source == but7) {
			if(n == "0")
				n="7";
			else 
				n = n + "7";
			label.setText(n);
		}
		if(source == but8) {
			if(n == "0")
				n="8";
			else 
				n = n + "8";
			label.setText(n);
		}
		if(source == but9) {
			if(n == "0")
				n="9";
			else 
				n = n + "9";
			label.setText(n);
		}
		if(source == butc) {
			sum = 0;
			num = 0;
			n = "0";
			addc=1;
			subc=0;
			label.setText(n);
		}
		if(source == but4) {
			if(n == "0")
				n="4";
			else 
				n = n + "4";
			label.setText(n);
		}
		if(source == but5) {
			if(n == "0")
				n="5";
			else 
				n = n + "5";
			label.setText(n);
		}
		if(source == but6) {
			if(n == "0")
				n="6";
			else 
				n = n + "6";
			label.setText(n);
		}
		if(source == but_add) {
			if(addc == 1)
			{
				num = num_reader();
				sum += num;
			}
			n = "0";
			addc=1;
			subc=0;
		}
		if(source == but1) {
			if(n == "0")
				n="1";
			else 
				n = n + "1";
			label.setText(n);
		}
		if(source == but2) {
			if(n == "0")
				n="2";
			else 
				n = n + "2";
			label.setText(n);
		}
		if(source == but3) {
			if(n == "0")
				n="3";
			else 
				n = n + "3";
			label.setText(n);
		}
		if(source == but_sub) {
			if(subc == 1)
			{
				num = num_reader();
				sum -= num;
			}
			else if(addc == 1)
			{
				num = num_reader();
				sum += num;
			}
			
			n = "0";
			addc=0;
			subc=1;
		}
		if(source == but0) {
			if(n == "0")
				n="0";
			else 
				n = n + "0";
			label.setText(n);
		}
		if(source == but_equal) {
			if(addc == 1)
			{
				num = num_reader();
				sum += num;
			}
			else if(subc == 1)
			{
				num = num_reader();
				sum -= num;
			}
			label.setText(String.valueOf(sum));
			sum = 0;
			n="0";
			addc=1;
			subc=0;
		}
		
	}
	int num_reader() {
		int num;
		String s;
		s = label.getText();
		num = Integer.valueOf(s);
		
		return num;
	}
}


public class Hw4 extends JFrame{
	
	Hw4Label label = new Hw4Label();
	public static void main(String[] args) {
		new Hw4();	
	}
	Hw4(){
		setSize(500,500);
		setTitle("Homework4");
		setLayout(new BorderLayout(50,10));
		add(label, BorderLayout.NORTH);
		add(new Hw4Panel(label),BorderLayout.CENTER);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
