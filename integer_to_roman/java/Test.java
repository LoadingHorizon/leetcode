import java.lang.reflect.Method;

public class Test {
    private static Method method_;
    private static Class class_;

    private static void test_cases() throws Throwable {
        test_case(new Object[]{10}, "X");
        test_case(new Object[]{3999}, "MMMCMXCIX");
        test_case(new Object[]{1899}, "MDCCCXCIX");
        // TODO add your case here
    };

    private static void test_case(Object[] args, Object ret) throws Throwable {
        String result = (String) method_.invoke(class_.newInstance(), args);
        String expect = (String) ret;
        try {
            assert result.equals(expect);
        } catch (AssertionError e) {
            int num = (int) args[0];
            System.out.println("test case failed: ");
            System.out.println("    num: " + args[0]);
            System.out.println("    expect: " + expect);
            System.out.println("    result: " + result);
        }
    }

    @SuppressWarnings("unchecked")
    public static void test(Class c) throws Throwable {
        class_ = c;
        method_ = c.getMethod("intToRoman", new Class[]{int.class});
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
