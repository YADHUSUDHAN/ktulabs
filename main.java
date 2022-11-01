import java.io.*;
public class main {
    public  static void main(String args[])throws Exception{
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter your name");
        String name = br.readLine();
        System.out.println("Enter your age : ");
        int age = Integer.parseInt(br.readLine());
        System.out.println("Age is : "+age);
        System.out.println("Welcome "+name);
    }
    
}
