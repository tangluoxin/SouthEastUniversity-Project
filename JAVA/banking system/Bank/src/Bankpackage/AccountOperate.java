package Bankpackage;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class AccountOperate {

		Bank[] AccountArray = new Bank[100];
		int count = 0;
		AccountOperate(){
			
		}
		    //�ж��û��Ƿ����
			boolean isExist(String name) {
				for(int i=0;i<count;i++) {
					if(AccountArray[i].getname().equalsIgnoreCase(name)) {
						return true;
					}
				}
				return false; 
			}
			//�ȶ����������Ƿ�ƥ��
			boolean isMatched(String name, String password) {
				for(int i=0;i<count;i++) {
					if((AccountArray[i].getname().equalsIgnoreCase(name))&&(AccountArray[i].getpassword().equalsIgnoreCase(password))) {
						return true;
					}
				}
				return false;
			}
			
			//�ȶ��û�������bank�������жϴ���Ƿ�ɹ�
			synchronized boolean addBalance(String name, float money) {
				for(int i=0;i<count;i++) {
					if(AccountArray[i].getname().equalsIgnoreCase(name)) {
						AccountArray[i].addbalance(money);
						return true;
					}
				}
				return false;
			}
			//�ȶ��û�������bank����ȡ��ж�ȡ���Ƿ�ɹ�
			synchronized boolean reduceBalance(String name, float change) {
				for(int i=0;i<count;i++) {
					if(AccountArray[i].getname().equalsIgnoreCase(name)) {
						boolean b = AccountArray[i].reducebalance(change);
						return b;
					}
				}
				return false;
			}
	    //д��
		synchronized void writeAccount(String filepath) {
			//synchronized��ס���Ǹ����ʵ������
			DataOutputStream dos = null;
			
			try {
				dos = new DataOutputStream(new FileOutputStream(new File(filepath)));
				for(int i=0; i < count; i++) {
					dos.writeUTF(AccountArray[i].getname());
					dos.writeUTF(AccountArray[i].getpassword());
					float fbalance = AccountArray[i].getbalance();
					
					String sbalance = Float.toString(fbalance);
					dos.writeUTF(sbalance);
				}
			} catch (IOException e) {
				System.out.println(e);
			} finally {
				try {if(dos != null) dos.close();
				}catch (IOException e) {System.out.println(e);}
			}		
		}
		
		//��ȡ
		synchronized void readAccount(String filepath) {
			
			DataInputStream dis = null;
			try {
				dis = new DataInputStream(new FileInputStream(new File(filepath)));
				while(true) {
					String sname   = dis.readUTF();//readUTF()ֻ�ܶ�ȡwriteUTFд��
					String spassword = dis.readUTF();
					String sbalance = dis.readUTF();
					float fbalance = Float.parseFloat(sbalance);
					AccountArray[count] = new Bank(sname,spassword,fbalance);
					count++;
				}
			} catch(EOFException e) {
					
			} catch(IOException e) {
				System.out.println(e);
			} finally {
				try {
					if(dis != null) dis.close();
				} catch(Exception e) { System.out.println(e);}
			}
		}
		
		//��ʼע��
		synchronized void registeredAccount(String name, String password, float balance) {
				String sname = name;
				String spassword = password;
				float fbalance = balance;
				AccountArray[count] = new Bank(sname, spassword, fbalance);
				count++;
			}
		
		//���ش���
				float getBalance(String name) {
					for(int i=0;i<count;i++) {
						if(AccountArray[i].getname().equalsIgnoreCase(name)) {
							float balance = AccountArray[i].getbalance();
							return balance;
						}
					}
					System.out.println("�û�������");
					return 0;
				}
		
	}		

	
	
	



