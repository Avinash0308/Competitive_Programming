import java.io.*;

class Cricket implements Serializable {
    int run;
    transient String name;

    public Cricket(int run, String name){
        this.run=run;
        this.name=name;
    }

    public void disp(){
        System.out.println(name);
        System.out.println(run);
    }
}

public class IO_8 {
    public static void main(String[] args) throws Exception {
        Cricket c= new Cricket(23, "Rohit");
        // Serialization
        FileOutputStream fos = new FileOutputStream("Design.txt");
        BufferedOutputStream bof = new BufferedOutputStream(fos);
        ObjectOutputStream oos = new ObjectOutputStream(bof);

        oos.writeObject(c);
        oos.flush();
        oos.close();

        // Deserialization
        FileInputStream fis = new FileInputStream("Design.txt");
        ObjectInputStream ois = new ObjectInputStream(fis);
        try {
            Cricket cr = (Cricket) ois.readObject();
            cr.disp();
        } catch (ClassNotFoundException e) {
            e.printStackTrace(); // Handle class not found exception
        }

        ois.close();
    }
}
