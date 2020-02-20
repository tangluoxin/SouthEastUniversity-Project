package Bankpackage;

import java.io.*;
import java.net.*;
import javax.swing.*;



public class Bank {
	
	private String name;
	private String password;
	private float balance;
	
	public Bank(String sname, String spassword) {
		name = sname;
		password = spassword;
		balance = 0;
		if((name != null)&&(password != null)) {
			AccountOperate b = new AccountOperate();
			b.registeredAccount(name, password, balance);
			b.writeAccount("account.txt");
		}
	} 
	public Bank(String sname, String spassword,float sbalance) {
		name=sname;
		password=spassword;
		balance=sbalance;
	}
	public String getname() {
		return name;
	}	
	public String getpassword() {
		return password;
	}	
	public float getbalance() {
		return balance;
	}
	public void setbalance(float b) {
		balance=b;
	}	
	public synchronized boolean addbalance(float money) {
		balance = balance + money;
		return true;
	}
	public synchronized boolean reducebalance(float money) {
		if(balance >= money) {
			balance = balance - money;
			return true;
		}
		else {
			return false;
		}
	}
	
	
	JFrame bank;
	JTextArea textbank;
	//界面
	public void BankFrame() {
	    bank = new JFrame();
		bank.setTitle("Bank");
		bank.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		bank.setSize(500,500);	
		
		textbank = new JTextArea();
		textbank.setSize(500, 500);
			
    	bank.add(textbank);
		bank.setVisible(true);
	}
	ServerSocket server;
    Socket ss;
    Socket client;
    PrintWriter out;
    int port = 9999;
	 
    
	public void initServerSocket() {
        try {
            server = new ServerSocket(port);
        } catch (IOException e) {
            System.out.println(e);
        }
    }

    public void WaitCalling() {
        try {
            while(true){
                ss = server.accept();
                BankThread t = new BankThread();
                t.start();
            }
        } catch (IOException e) {
            System.out.println(e);
        }

    }
    
    
	public static void main(String[] args) throws InterruptedException {
		// TODO Auto-generated method stub
		Bank a = new Bank("", "");
		a.AddInterests();
		a.initServerSocket();
		a.BankFrame();
		a.WaitCalling();
		
        
        
	}
	//银行线程
	public class BankThread extends Thread {

		public void run() {
		  try {
			BufferedReader in = new BufferedReader(
					new InputStreamReader(ss.getInputStream()));
			PrintWriter out = new PrintWriter(
	                new BufferedWriter(new OutputStreamWriter(ss.getOutputStream())), true);
			while(true) {
				String str = in.readLine();
				System.out.println(str);
				textbank.append(str);
				if(str!=null) {
					if("login".equals(str)) {
						String _name=in.readLine();
						String _password=in.readLine();
						
						AccountOperate account = new AccountOperate();
						account.readAccount("account.txt");
						
						if(account.isExist(_name)) {
							if(account.isMatched(_name, _password)) {
								
								out.println("login");
								
								float _balance = account.getBalance(_name);
								textbank.append(_name+":"+_balance+"\n");
							}else {
								out.println("loginfaul");
							}
								
						}else {
							out.println("loginnull");
							textbank.append("faul"+_name+"\n");
						}
							 
					}else if("exit".equals(str)) {
						String _name=in.readLine();
						
						AccountOperate account = new AccountOperate();
					    account.readAccount("account.txt");
					    
						out.println("exit");
						
						float _balance = account.getBalance(_name);
						textbank.append(_name+":"+_balance+"\n");
					}else if("reg".equals(str)) {
						String _name=in.readLine();
						String _password=in.readLine();
						
						AccountOperate account = new AccountOperate();
					    account.readAccount("account.txt");
					    if(_name != null&&_password != null) {
							account.registeredAccount(_name, _password, 0);
							account.writeAccount("account.txt");
							
							out.println("reg");
							
							float _balance = account.getBalance(_name);
							textbank.append(_name+":"+_balance+"\n");
						}else {
							out.println("regfaul");
							textbank.append("faul"+_name+"\n");
						} 
					}else if("deposit".equals(str)) {
						String _name=in.readLine();
						String _money=in.readLine();
						float fmoney = Float.parseFloat(_money);
						
						AccountOperate account = new AccountOperate();
						account.readAccount("account.txt");
						if(account.addBalance(_name, fmoney)) {
							
							account.writeAccount("account.txt");
							out.println("deposit");
							
							float _balance = account.getBalance(_name);
							textbank.append(_name+":"+_balance+"\n");
							
						}
						else {
							out.println("depositfaul");
							textbank.append("faul"+_name+"\n");
							}
					}else if("withdraw".equals(str)) {
						
						String _name=in.readLine();
						String _money=in.readLine();
						float fmoney = Float.parseFloat(_money);
						
						AccountOperate account = new AccountOperate();
						account.readAccount("account.txt");
						
						if(account.reduceBalance(_name, fmoney)) {
							
							account.writeAccount("account.txt");
							out.println("withdraw");
							
							float _balance = account.getBalance(_name);
							textbank.append(_name+":"+_balance+"\n");
							
							
						}
						else {
							out.println("withdrawfaul");
							textbank.append("faul"+_name+"\n");
						}	
					}else if("query".equals(str)) {
						String _name=in.readLine();
						
						AccountOperate account = new AccountOperate();
						account.readAccount("account.txt");
						
						float _balance = account.getBalance(_name);
						String sbalance = Float.toString(_balance);
						
						textbank.append(_name+":"+_balance+"\n");
						
						out.println("query");
						out.println(sbalance);
						
					}
					
					
					 
				}
			}
		 } catch (IOException e){
			System.out.println(e);
		}

	}
}
	
	public void AddInterests() throws InterruptedException {
		Thread b = new Thread(new Interests());
		b.start();
}

	//增加利息
	public class Interests implements Runnable {

		public void run() {
			while(true) { 
				try {
					
					Thread.sleep(20*1000L);
                    System.out.println("增加利息");
                    
					AccountOperate account = new AccountOperate();
					account.readAccount("account.txt");
					
					for(int i=0;i<account.count;i++) {
						float a = account.AccountArray[i].getbalance();
						a = (float) (a * 1.03);
						account.AccountArray[i].setbalance(a);
					}
					
					account.writeAccount("account.txt");
					
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} 
			}
		}
	}
	
	
    
	
}
 



