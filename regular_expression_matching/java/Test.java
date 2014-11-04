import java.lang.reflect.Method;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{"aa", "a"}, false);
        test_case(new Object[]{"aa", "aa"}, true);
        test_case(new Object[]{"aaa", "aa"}, false);
        test_case(new Object[]{"aa", "a*"}, true);
        test_case(new Object[]{"aa", ".*"}, true);
        test_case(new Object[]{"ab", ".*"}, true);
        test_case(new Object[]{"ab", ".*c"}, false);
        test_case(new Object[]{"aab", "c*a*b"}, true);
        test_case(new Object[]{"aaa", "a*a"}, true);
        // TODO add your case here
    };

    private static void test_case(Object[] args, Object ret) throws Throwable {
        boolean result = (boolean) method_.invoke(class_.newInstance(), args);
        boolean expect = (boolean) ret;
        try {
            assert result == expect;
        } catch (AssertionError e) {
            String s = (String) args[0];
            String p = (String) args[1];
            System.out.println("test case failed: ");
            System.out.println("    s: " + args[0]);
            System.out.println("    p: " + args[1]);
            System.out.println("    expect: " + expect);
            System.out.println("    result: " + result);
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("isMatch", new Class[]{String.class, String.class});
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
