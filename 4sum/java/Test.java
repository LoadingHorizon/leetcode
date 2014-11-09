import java.lang.reflect.Method;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{new int[]{-1, 0, 1, 0, -2, 2}, 0}, new ArrayList<ArrayList<Integer>>(){{
            add(new ArrayList<Integer>(Arrays.asList(-1, 0, 0, 1)));
            add(new ArrayList<Integer>(Arrays.asList(-2, -1, 1, 2)));
            add(new ArrayList<Integer>(Arrays.asList(-2, 0, 0, 2)));
        }});
        // TODO add your case here
    };

    @SuppressWarnings("unchecked")
    private static void test_case(Object[] args, Object ret) throws Throwable {
        List<List<Integer>> result = (List<List<Integer>>) method_.invoke(class_.newInstance(), args);
        List<List<Integer>> expect = (List<List<Integer>>) ret;
        try {
            assert result.size() == expect.size();
            for (int i = 0; i < result.size(); i++) {
                assert result.contains(expect.get(i));
            }
        } catch (AssertionError e) {
            int[] num = (int[]) args[0];
            int target = (int) args[1];
            String numStr = "[";
            for (int i = 0; i < num.length; i++) {
                numStr += num[i] + ", ";
            }
            numStr = numStr.substring(0, numStr.length() - 2);
            numStr += "]";
            System.out.println("test case failed: ");
            System.out.println("    num: " + args[0]);
            System.out.println("    target: " + args[1]);
            System.out.println("    expect: " + expect);
            System.out.println("    result: " + result);
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("fourSum", new Class[]{int[].class, int.class});
        test_cases();
    }

    public static void main(String[] args) throws Throwable {
        if (args.length != 1) {
            System.out.println("Usage: java -ea Test <package>");
            System.out.println("    eg: java -ea Test pj");
            System.out.println("    eg: java -ea Test hl");
            return;
        }

        test(Class.forName(args[0] + ".Solution"));
    }
}
