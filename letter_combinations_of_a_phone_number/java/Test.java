import java.lang.reflect.Method;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{"23"}, new ArrayList<String>(Arrays.asList(
                        "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf")));
        // TODO add your case here
    };

    @SuppressWarnings("unchecked")
    private static void test_case(Object[] args, Object ret) throws Throwable {
        List<String> result = (List<String>) method_.invoke(class_.newInstance(), args);
        List<String> expect = (List<String>) ret;
        try {
            assert result.size() == expect.size();
            for (int i = 0; i < expect.size(); i++) {
                assert result.contains(expect.get(i));
            }
        } catch (AssertionError e) {
            String digits = (String) args[0];
            System.out.println("test case failed: ");
            System.out.println("    digits: " + args[0]);
            System.out.println("    expect: " + expect);
            System.out.println("    result: " + result);
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("letterCombinations", new Class[]{String.class});
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
