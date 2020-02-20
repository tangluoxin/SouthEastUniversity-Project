package Bankpackage;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.*;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;





public class RegisterPanel extends JPanel{
	
	JFrame atm;
	
	JLabel     labelname;      
	JLabel     labelpassword;     
	JLabel     labelbalance;      //�˻����
	JLabel     labelmoney;      //�������
	
	JTextField textname; 
	JTextField textpassword; 
	JTextField textbalance; 
	JTextField textmoney; 
	JTextField textback; //ϵͳ����
	
	JButton btnlist[];
	JButton btnlisttwo[];
	
	ServerSocket s;//�ȴ��ͻ��˵�����
	                    //һ�����һ���������󣬾ʹ���һ��Socketʾ������ͻ��˽���ͨ�š� 
	 ServerSocket server;
	    Socket ss;
	    Socket client;
	    PrintWriter out;
	    int port = 9999;
	
	
	public RegisterPanel(){
		//this.setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		this.setLayout(new GridLayout(7,1));//����һ�����񲼾�
		
		this.setName("ATM");
		
		labelname      = new JLabel("         ����");
		labelpassword  = new JLabel("        ����");
		labelbalance   = new JLabel("�˻����");
		labelmoney     = new JLabel("�������");
		
		
		textname  = new JTextField(20);
		textpassword  = new JTextField(20);
		textbalance  = new JTextField(20);
		textmoney  = new JTextField(20);
		textback  = new JTextField(40);//�����ʾ
	
		JPanel[] plist = new JPanel[7];
		for(int i = 0; i < 7; i++){
			plist[i] = new JPanel(new FlowLayout(FlowLayout.LEFT));
			this.add(plist[i]);
		}
		
		plist[0].setLayout(new FlowLayout(FlowLayout.CENTER));
		plist[0].add(labelname);
		plist[0].add(textname);
		
		plist[1].setLayout(new FlowLayout(FlowLayout.CENTER));
		plist[1].add(labelpassword);
		plist[1].add(textpassword);
		
		plist[2].setLayout(new FlowLayout(FlowLayout.CENTER));
		plist[2].add(labelbalance);
		plist[2].add(textbalance);
		
		plist[3].setLayout(new FlowLayout(FlowLayout.CENTER));
		plist[3].add(labelmoney);
		plist[3].add(textmoney);
		
		plist[4].setLayout(new FlowLayout(FlowLayout.CENTER));
		plist[4].add(textback);
		
		plist[5].setLayout(new FlowLayout(FlowLayout.CENTER));
		btnlist = new JButton[3];
		btnlist[0] = new JButton("��¼");
		btnlist[1] = new JButton("�˳�");
		btnlist[2] = new JButton("ע��");
		plist[5].add(btnlist[0]);
		plist[5].add(btnlist[1]);
		plist[5].add(btnlist[2]);
		
		plist[6].setLayout(new FlowLayout(FlowLayout.CENTER));
		btnlisttwo = new JButton[3];
		btnlisttwo[0] = new JButton("��Ǯ");
		btnlisttwo[1] = new JButton("ȡǮ");
		btnlisttwo[2] = new JButton("��ѯ");
		plist[6].add(btnlisttwo[0]);
		plist[6].add(btnlisttwo[1]);
		plist[6].add(btnlisttwo[2]);
		
		//�����ע������ڲ���
		btnlist[0].addActionListener(new ButtonActionListener1());
		btnlist[1].addActionListener(new ButtonActionListener2());
		btnlist[2].addActionListener(new ButtonActionListener3());
		btnlisttwo[0].addActionListener(new ButtonActionListener4());
		btnlisttwo[1].addActionListener(new ButtonActionListener5());
		btnlisttwo[2].addActionListener(new ButtonActionListener6());
	}
	
/*	Java Swing�д��������¼���һ�㲽���ǣ�
	����
	����1�� �½�һ���������JButton����
	����
	����2�� ���������ӵ���Ӧ����壨��JPanel����
	����
	����3�� ע��������Լ����¼�Դ�������¼�����ͨ��ActionListener����Ӧ�û������ť����
	����
	����4�� ���崦���¼��ķ���������ActionListener�е�actionPerformed�ж�����Ӧ��������
	
	ʹ��һ��������ڲ�����Խ��������⡣ 
	���е��¼���������������һ�飬���Ҷ���������������ƣ�����ǳ������Ķ���ά�����������¼��������Ҳ���Ա����������˵������ظ�ʹ��
	
	��button1.addActionListener(new ButtonActionListener1());�����ע������ڲ���*/
	
	//һ��������ڲ���ButtonActionListener1ʵ��
	//��¼
	private class ButtonActionListener1 implements ActionListener{
		//���崦���¼��ķ���������ActionListener�е�actionPerformed�ж�����Ӧ������
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			try{
				out.println("login");
				out.println(textname.getText());
				out.println(textpassword.getText());
				
			} catch (Exception ioe){
				System.out.println(ioe);
			}		
		}
	}
	//һ��������ڲ���ButtonActionListener2ʵ��
	//�˳�
	private class ButtonActionListener2 implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			try{
				out.println("exit");
				out.println(textname.getText());
				
			} catch (Exception ioe){
				System.out.println(ioe);
			}	
		}
	}
	//һ��������ڲ���ButtonActionListener3ʵ��
	//ע��
	private class ButtonActionListener3 implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			try{
				out.println("reg");
				out.println(textname.getText());
				out.println(textpassword.getText());
				
			} catch (Exception ioe){
				System.out.println(ioe);
			}	
		}
	}
	//һ��������ڲ���ButtonActionListener4ʵ��
	//���
	private class ButtonActionListener4 implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			try{
				out.println("deposit");
				out.println(textname.getText());
				out.println(textmoney.getText());		
				
			} catch (Exception ioe){
				System.out.println(ioe);
			}	
		}
	}
	//һ��������ڲ���ButtonActionListener5ʵ��
	//ȡ��
	private class ButtonActionListener5 implements ActionListener{
		public void actionPerformed(ActionEvent e) {
			try{
				out.println("withdraw");
				out.println(textname.getText());
				out.println(textmoney.getText());	
				
			} catch (Exception ioe){
				System.out.println(ioe);
			}	
		}
	}
	//һ��������ڲ���ButtonActionListener6ʵ��
	//��ѯ
	private class ButtonActionListener6 implements ActionListener{
		public void actionPerformed(ActionEvent e) {			
			try{
				out.println("query");
				out.println(textname.getText());				
				
			} catch (Exception ioe){
				System.out.println(ioe);
			}	
		}
	}
	
	
	private class ATMThread extends Thread{


		public void run(){
			try{
				BufferedReader in = new BufferedReader(
						new InputStreamReader(client.getInputStream()));
				while (true) {
					String str = in.readLine();
					//
					if (str != null) {
						
						if("login".equals(str)) {
							textback.setText("��¼�ɹ�");
						}else if("loginfaul".equals(str)) {
							textback.setText("��¼ʧ��");
						}else if("loginnull".equals(str)) {
							textback.setText("�û���������");
						}
						
						else if("exit".equals(str)) {
							 textname.setText(null);
							    textpassword.setText(null);
							    textbalance.setText(null);
							    textmoney.setText(null);						
							    textback.setText(null);
						}
						
						else if("reg".equals(str)) {
							textback.setText("ע��ɹ�");
						}else if("regfaul".equals(str)) {
							textback.setText("�û������벻��Ϊ��");
						}
						
						else if("deposit".equals(str)) {
							textback.setText("���ɹ�");
						}else if("depositfaul".equals(str)) {
							textback.setText("���ʧ��");
						}
						
						else if("withdraw".equals(str)) {
							textback.setText("ȡ��ɹ�");
						}else if("withdrawfaul".equals(str)) {
							textback.setText("ȡ��ʧ��");
						}
						
						else if("query".equals(str)) { 
							String sbalance = in.readLine();
							textbalance.setText(sbalance);
							textback.setText(null);
						}

					} else {
						break;
					}
				}

			} catch (IOException e){
				System.out.println(e);
			}
		}
	}

	public void ATMframe(RegisterPanel a) {
		atm = new JFrame();
		atm.setTitle("ATM");
		atm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		atm.add(a);
		atm.setSize(500,500);	
		atm.setVisible(true);
	}
	
	public void ServerSocket() {
        try {
            client = new Socket("127.0.0.1",port);
            out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(client.getOutputStream())), true);
            ATMThread t = new ATMThread();
            t.start();

        } catch (IOException e) {
            System.out.println(e);
        }
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		RegisterPanel a = new RegisterPanel();
		a.ServerSocket();
		a.ATMframe(a);
	}
	
}
