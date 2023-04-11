import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.math.BigInteger;

/**
 *
 * @author famil
 */
public class Main {

    public static void main(String[] args) {

        FastScanner sc = new FastScanner();

        int n,
            query = 1;

        char ch[];

        String cad,
                nueva = "",
                ant = "";
                ArrayList<String> queryList = new ArrayList<String>();
        
        boolean flag = false,
                salto = false;

        while (true) {
            n = sc.nextInt();

            if (n == 0) {
                break;
            }
            if(!salto){
                salto=true;
            }
            else{
                queryList.add("");
            }
            queryList.add("Case " + (query++) + ":"); 
            ch = sc.next().toCharArray();
            cad = new String(ch);
            ant=cad;
            for (int i = 1; i < n; i++) {
                ch = sc.next().toCharArray();
                nueva = new String(ch);
                if (continuo(ant, nueva)) {
                    // System.out.println("**"+i);
                    flag = true;
                } else {
                    if (flag == true) {
                        queryList.add(numero(cad, ant));
                    } 
                    else{
                        queryList.add(cad);
                    }
                    flag = false;
                    cad = nueva;
                }
                ant=nueva;
            }
            if (flag == true) {
                queryList.add(numero(cad, nueva));
            } 
            else{
                queryList.add(nueva);
            }
            flag=false;
        }
        for (String x: queryList) {
            System.out.println(x);
        }
    }

    static boolean continuo(String cad1, String cad2) {

        BigInteger a = new BigInteger(cad1),
                b = new BigInteger(cad2),
                uno = new BigInteger("1");
        a = a.add(uno);

        return a.compareTo(b) == 0;

    }

    static String numero(String cad, String cad2) {
        String tmp = "";
        for (int i = 0; i < cad.length(); i++) {
            if (cad.charAt(i) != cad2.charAt(i)) {
                tmp = "-" + cad2.substring(i);
                break;
            }
        }
        return cad+tmp;
    }

    public static class FastScanner {

        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String next() {
            while (!st.hasMoreTokens())
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

}