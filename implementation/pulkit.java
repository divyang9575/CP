import java.util.*;

public class RoundRobin {
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }

        public int getFirst() {
            return first;
        }

        public int getSecond() {
            return second;
        }
    }

    public static List<Integer> round(int n, List<Integer> arrival, List<Integer> burst) {
        PriorityQueue<Pair> q = new PriorityQueue<>(Comparator.comparingInt(Pair::getFirst));
        int m = arrival.size();

        List<List<Integer>> ar = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            List<Integer> temp = new ArrayList<>();
            temp.add(arrival.get(i));
            temp.add(burst.get(i));
            temp.add(i);
            ar.add(temp);
        }

        ar.sort(Comparator.comparingInt(a -> a.get(0)));
        
        TreeSet<Integer> st = new TreeSet<>();
        for (int i = 1; i <= n; i++) {
            st.add(i);
        }

        List<Integer> ans = new ArrayList<>(Collections.nCopies(m, 0));
        for (int i = 0; i < m; i++) {
            while (!q.isEmpty() && q.peek().first <= ar.get(i).get(0)) {
                st.add(q.poll().second);
            }
            int ind = st.first();
            ans.set(ar.get(i).get(2), ind);
            q.add(new Pair(ar.get(i).get(0) + ar.get(i).get(1), ind));
            st.remove(ind);
        }

        return ans;
    }

    public static void solve(Scanner sc) {
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        List<Integer> arr = new ArrayList<>();
        List<Integer> brr = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            arr.add(sc.nextInt());
        }
        for (int i = 0; i < m; i++) {
            brr.add(sc.nextInt());
        }

        List<Integer> ans = round(n, arr, brr);
        for (int i = 0; i < m; i++) {
            System.out.print(ans.get(i) + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = 1; // In the given code, the number of test cases is fixed at 1
        while (t-- > 0) {
            solve(sc);
        }
    }
}
