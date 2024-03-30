package Singleton;

public class Singleton {
    private static Singleton singleton;

    private Singleton() {
    }

    // Lazy way of creating
    public static Singleton getSingleton() {
        if (singleton == null) {
            synchronized (Singleton.class) {
                singleton = new Singleton();
            }
        }

        return singleton;
    }
}
