import java.util.*;

public class Bot {
    private Point current;
    
    public Bot(Point start) {
        this.current = start;
    }

    public Point getCurrent() {
        return this.current;
    }

    public void move(Point next) {
        this.current = next;
    }
}
