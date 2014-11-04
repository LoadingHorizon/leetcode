import java.lang.reflect.Method;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{12321}, true);
        test_case(new Object[]{123}, false);
        // TODO add your case here
    };

    private static void test_case(Object[] args, Object ret) throws Throwable {
        boolean result = (boolean) method_.invoke(class_.newInstance(), args);
        boolean expect = (boolean) ret;
        try {
            assert result == expect;
        } catch (AssertionError e) {
            int x = (int) args[0];
            System.out.println("test case failed: ");
            System.out.println("    x: " + args[0]);
            System.out.println("    expect: " + expect);
            System.out.println("    result: " + result);
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("isPalindrome", new Class[]{int.class});
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
