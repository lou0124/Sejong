
import java.awt.Color;
import java.awt.Font;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.geom.Rectangle2D;
import java.io.File;
import java.net.URL;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.swing.JFrame;
import javax.swing.JPanel;


class MakeBrick{
	int brick[][];
	int brickWidth;
	int brickHeight;
	MakeBrick(int row, int col){
		brick = new int[row][col]; 
		
		for(int i=0;i<brick.length;i++) {
			for(int j=0;j<brick[0].length;j++) {
				brick[i][j] = 1;
			}
		}
		
		brickWidth = 800/col;
		brickHeight = 350/row;
	}
	void draw(Graphics2D g) {
		for(int i=0;i<brick.length;i++) {
			for(int j=0;j<brick[0].length;j++) {
				if(brick[i][j] == 1) {
					Graphics2D g2 = (Graphics2D) g ;
					GradientPaint gp = 
							new GradientPaint(0,i*brickHeight+5,new Color(0xFFFFFF),0,i*brickHeight +5 + brickHeight,new Color(0x000000));
					g2.setPaint(gp);
					g2.fill(new Rectangle2D.Float(j*brickWidth, i*brickHeight, brickWidth, brickHeight));
					
					g.setColor(new Color(0x800080));
					g.fillRect(j*brickWidth + 1, i*brickHeight +1, brickWidth-1, brickHeight-3);
				}
			}
		}
	}
}

class GamePlay extends JPanel implements KeyListener, Runnable{
	int play = 0;
	int score = 0;
	int high_score = 0;
	int total_brick;
	int paddleX;
	int px;
	int py;
	int dx;
	int dy;
	int stage = 1;
	
	Thread t;
	
	Clip clip;
	Clip clip2;
	Clip clip3;
	Clip clip4;
	MakeBrick map;
	
	GamePlay(){
		try {
			clip = AudioSystem.getClip();
			//File audioFile = new File("fight.wav");
			URL url = getClass().getResource("fight.wav");
			AudioInputStream stream = AudioSystem.getAudioInputStream(url);
			clip.open(stream);
			
			clip2 = AudioSystem.getClip();
			//File audioFile2 = new File("tick.wav");
			URL url2 = getClass().getResource("tick.wav");
			AudioInputStream stream2 = AudioSystem.getAudioInputStream(url2);
			clip2.open(stream2);
	
			
			clip3 = AudioSystem.getClip();
			//File audioFile3 = new File("tok.wav");
			URL url3 = getClass().getResource("tok.wav");
			AudioInputStream stream3 = AudioSystem.getAudioInputStream(url3);
			clip3.open(stream3);
			
			clip4 = AudioSystem.getClip();
			//File audioFile4 = new File("out.wav");
			URL url4 = getClass().getResource("out.wav");
			AudioInputStream stream4 = AudioSystem.getAudioInputStream(url4);
			clip4.open(stream4);
			
		} catch (Exception  e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		map = new MakeBrick(3,7);
		addKeyListener(this);
		setFocusable(true);
		requestFocus();
		t = new Thread(this);
		t.start();
	}
	
	public void paint(Graphics g) {
		Graphics2D g2 = (Graphics2D) g ;
		GradientPaint gp = new GradientPaint(0,0,new Color(0x000000),0,this.getHeight(),new Color(0x696969));
		Graphics2D g3 = (Graphics2D) g ;
		GradientPaint gp3 = new GradientPaint(0,730,new Color(0xe5dedb),0,750,new Color(0x000000));
		if(play == 0)
		{
			clip.loop(Clip.LOOP_CONTINUOUSLY);
			g2.setPaint(gp);
			g2.fill(new Rectangle2D.Float(0,0,800, 800));
			
			g.setColor(Color.white);
			g.setFont(new Font("serif", Font.BOLD, 60));
			g.drawString("Java Programming", 150, 150);
			g.drawString("Homework #5", 210, 200);
			g.setFont(new Font("ALGERIAN", Font.BOLD, 80));
			g.drawString("BLOCK BREAKER", 50, 400);
			
			
			g.setFont(new Font("±Ã¼­", Font.BOLD, 30));
			g.setColor(Color.red);
			g.drawString ("PRESS SPACEBAR TO PLAY", 180, 600);
		}
		if(play == 1) {
			clip.setFramePosition(0);
			clip.stop();
			//background
			g2.setPaint(gp);
			g2.fill(new Rectangle2D.Float(0,0,800, 800));
			
			map.draw((Graphics2D)g);
			
			// paddle
			
			g3.setPaint(gp3);
			g3.fill(new Rectangle2D.Float(paddleX,730, 150, 20));
			
			g.setColor(new Color(0x816558));
			g.fillRect(paddleX+1,730+1, 150-2, 20-2);
		
			// ball
			g.setColor(Color.white);
			g.fillOval(px, py, 20, 20);
			
				if(py > 800) {
					clip4.setFramePosition(0);
					clip4.start();
					play = 2;
				}
		}
		
		if(play == 2) {
			
			g2.setPaint(gp);
			g2.fill(new Rectangle2D.Float(0,0,800, 800));
			if(score > high_score) {
				high_score = score;
			}
			g.setColor(Color.white);
			g.setFont(new Font("ALGERIAN", Font.BOLD, 110));
			g.drawString("GAME OVER", 60, 300);
			g.setFont(new Font("serif", Font.BOLD, 30));
			g.setColor(Color.gray);
			g.drawString("HIGH SCORE: "+ high_score, 270, 400);
			g.drawString("YOUR SCORE: "+ score, 270, 450);
			g.setFont(new Font("±Ã¼­", Font.BOLD, 30));
			g.setColor(Color.red);
			g.drawString("PRESS SPACEBAR TO PLAY", 180, 600);	
		}
	}
	
	public void run() {		
		while(true) {
			if(play == 1) {
				if(new Rectangle(px, py, 20,20).intersects(new Rectangle(paddleX, 730 ,150,20))){
					clip2.setFramePosition(0);
					clip2.start();
					dy = -dy;
				}
				
		out:	for(int i=0;i<map.brick.length;i++) {
					for(int j= 0;j<map.brick[0].length;j++) {
						if(map.brick[i][j] == 1) {
							int brickX = j*map.brickWidth;
							int brickY = i*map.brickHeight;
							int brickWidth = map.brickWidth;
							int brickHeight = map.brickHeight;
							Rectangle rect = new Rectangle(brickX, brickY,brickWidth, brickHeight);
							Rectangle ballRect = new Rectangle(px, py, 20 ,20);
							Rectangle brickRect = rect;
							
							if(ballRect.intersects(brickRect)) {
								clip3.setFramePosition(0);
								clip3.start();
								map.brick[i][j] = 0;
								total_brick--;
								score += 10;
														
								
								if(px + 19 <= brickRect.x || px + 1 >= brickRect.x + brickRect.width) {
									dx = - dx;
								}
								else {
									dy = - dy;
								}
								
								
								if(total_brick <= 0)
								{
									stage ++;
									total_brick = (3*stage)*(3*stage);
									px = 350;
									py = 700;
									dx = -2;
									dy = -4;
									paddleX = 310;
									map = new MakeBrick(3*stage, 3*stage);
									repaint();
								}
								break out;
							}
						}
					}
				}
					
				px += dx;
				py += dy;
				if(px < 0) {
					dx = -dx;
				}
				if(py < 0) {
					dy = -dy;
				}
				if(px > 770) {
					dx = -dx;
				}
				
			}
			
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				return;
			}
			repaint();
		}
	}
	
	
	public void keyTyped(KeyEvent e) {}
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_RIGHT) {
			if(paddleX>=640){
				paddleX = 640;
			}
			else {
				paddleX += 20;
			}
		}
		if(e.getKeyCode() == KeyEvent.VK_LEFT) {
			if(paddleX<10){
				paddleX = 0;
			}
			else {
				paddleX -= 20;
			}
		}
		if(e.getKeyCode() == KeyEvent.VK_SPACE) {
			
			if(play == 0) {
				play = 1;
				stage = 1;
				total_brick = (3*stage)*(3*stage);
				px = 350;
				py = 700;
				dx = -2;
				dy = -4;
				paddleX = 310;
				score = 0;
				map = new MakeBrick(3*stage, 3*stage);
				repaint();
			}
			else if(play == 2){
				play = 0;
			}
		} 
	}
	public void keyReleased(KeyEvent e) {}

}

public class Hw5 extends JFrame{

	public static void main(String[] args) {
		new Hw5();
	}
	Hw5(){
		setSize(800,800);
		setTitle("Java Homework5");
		setResizable(false);
		add(new GamePlay());
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
	}

}
