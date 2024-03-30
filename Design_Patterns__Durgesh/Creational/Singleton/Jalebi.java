package Singleton;

public class Jalebi {
    // Eager way og creating
    private static Jalebi jalebi = new Jalebi();

    public static Jalebi getJalebi() {
        return jalebi;
    }
}
