public class Foo {
    public void method1() {
        System.out.println("foo 1");
    }

    public void method2() {
        System.out.println("foo 2");
    }

    public String toString() {
        return "foo";
    }

    public static void main(String[] args) {
        Foo foo = new Foo();
        Bar bar = new Bar();
        Baz baz = new Baz();
        Mumble mumble = new Mumble();

        foo.method1();
        foo.method2();
        System.out.println(foo.toString());

        bar.method1();
        bar.method2();
        System.out.println(bar.toString());
    }
}

class Bar extends Foo {
    public void method2() {
        System.out.println("bar 2");
    }
}

class Baz extends Foo {
    public void method1() {
        System.out.println("baz 1");
    }

    public String toString() {
        return "baz";
    }
}

class Mumble extends Baz {
    public void method2() {
        System.out.println("mumble 2");
    }
}
