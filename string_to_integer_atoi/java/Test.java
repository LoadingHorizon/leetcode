import java.lang.reflect.Method;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{"123"}, 123);
        test_case(new Object[]{"-123"}, -123);
        test_case(new Object[]{""}, 0);
        test_case(new Object[]{"+-2"}, 0);
        test_case(new Object[]{"-0012a42"}, -12);
        test_case(new Object[]{"2147483648"}, 2147483647);
        test_case(new Object[]{"-2147483648"}, -2147483648);
        test_case(new Object[]{"   010"}, 10);
        test_case(new Object[]{" b11228552307"}, 0);
        test_case(new Object[]{"   10522545459"}, 2147483647);
        // TODO add your case here
    };

    private static void test_case(Object[] args, Object ret) throws Throwable {
        int result = (int) method_.invoke(class_.newInstance(), args);
        int expect = (int) ret;
        try {
            assert result == expect;
        } catch (AssertionError e) {
            String str = (String) args[0];
            System.out.println("test case failed: ");
            System.out.println("    string: \"" + str + "\"");
            System.out.println("    expect: " + expect);
            System.out.println("    result: " + result);
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("atoi", new Class[]{String.class});
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
