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
	JLabel     labelbalance;      //账户余额
	JLabel     labelmoney;      //操作金额
	
	JTextField textname; 
	JTextField textpassword; 
	JTextField textbalance; 
	JTextField textmoney; 
	JTextField textback; //系统反馈
	
	JButton btnlist[];
	JButton btnlisttwo[];
	
	ServerSocket s;//等待客户端的请求，
	                    //一旦获得一个连接请求，就创建一个Socket示例来与客户端进行通信。 
	 ServerSocket server;
	    Socket ss;
	    Socket client;
	    PrintWriter out;
	    int port = 9999;
	
	
	public RegisterPanel(){
		//this.setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		this.setLayout(new GridLayout(7,1));//七行一列网格布局
		
		this.setName("ATM");
		
		labelname      = new JLabel("         姓名");
		labelpassword  = new JLabel("        密码");
		labelbalance   = new JLabel("账户余额");
		labelmoney     = new JLabel("操作金额");
		
		
		textname  = new JTextField(20);
		textpassword  = new JTextField(20);
		textbalance  = new JTextField(20);
		textmoney  = new JTextField(20);
		textback  = new JTextField(40);//结果显示
	
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
		btnlist[0] = new JButton("登录");
		btnlist[1] = new JButton("退出");
		btnlist[2] = new JButton("注册");
		plist[5].add(btnlist[0]);
		plist[5].add(btnlist[1]);
		plist[5].add(btnlist[2]);
		
		plist[6].setLayout(new FlowLayout(FlowLayout.CENTER));
		btnlisttwo = new JButton[3];
		btnlisttwo[0] = new JButton("存钱");
		btnlisttwo[1] = new JButton("取钱");
		btnlisttwo[2] = new JButton("查询");
		plist[6].add(btnlisttwo[0]);
		plist[6].add(btnlisttwo[1]);
		plist[6].add(btnlisttwo[2]);
		
		//对组件注册监听内部类
		btnlist[0].addActionListener(new ButtonActionListener1());
		btnlist[1].addActionListener(new ButtonActionListener2());
		btnlist[2].addActionListener(new ButtonActionListener3());
		btnlisttwo[0].addActionListener(new ButtonActionListener4());
		btnlisttwo[1].addActionListener(new ButtonActionListener5());
		btnlisttwo[2].addActionListener(new ButtonActionListener6());
	}
	
/*	Java Swing中处理各组件事件的一般步骤是：
	　　
	　　1． 新建一个组件（如JButton）。
	　　
	　　2． 将该组件添加到相应的面板（如JPanel）。
	　　
	　　3． 注册监听器以监听事件源产生的事件（如通过ActionListener来响应用户点击按钮）。
	　　
	　　4． 定义处理事件的方法（如在ActionListener中的actionPerformed中定义相应方法）。
	
	使用一般的命名内部类可以解决许多问题。 
	所有的事件处理方法都集中在一块，并且都具有有意义的名称，程序非常容易阅读与维护。单个的事件处理程序也可以被工具栏、菜单栏等重复使用
	
	用button1.addActionListener(new ButtonActionListener1());对组件注册监听内部类*/
	
	//一般的命名内部类ButtonActionListener1实现
	//登录
	private class ButtonActionListener1 implements ActionListener{
		//定义处理事件的方法（如在ActionListener中的actionPerformed中定义相应方法）
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
	//一般的命名内部类ButtonActionListener2实现
	//退出
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
	//一般的命名内部类ButtonActionListener3实现
	//注册
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
	//一般的命名内部类ButtonActionListener4实现
	//存款
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
	//一般的命名内部类ButtonActionListener5实现
	//取款
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
	//一般的命名内部类ButtonActionListener6实现
	//查询
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
							textback.setText("登录成功");
						}else if("loginfaul".equals(str)) {
							textback.setText("登录失败");
						}else if("loginnull".equals(str)) {
							textback.setText("用户名不存在");
						}
						
						else if("exit".equals(str)) {
							 textname.setText(null);
							    textpassword.setText(null);
							    textbalance.setText(null);
							    textmoney.setText(null);						
							    textback.setText(null);
						}
						
						else if("reg".equals(str)) {
							textback.setText("注册成功");
						}else if("regfaul".equals(str)) {
							textback.setText("用户名密码不能为空");
						}
						
						else if("deposit".equals(str)) {
							textback.setText("存款成功");
						}else if("depositfaul".equals(str)) {
							textback.setText("存款失败");
						}
						
						else if("withdraw".equals(str)) {
							textback.setText("取款成功");
						}else if("withdrawfaul".equals(str)) {
							textback.setText("取款失败");
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
