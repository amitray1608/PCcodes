package music;

interface Playable {
  void play();
}

package music.string;

class Veena implements Playable {
  void play() {
    System.out.println("Veena Play");
  }
}

package music.wind;

class Saxophone implements Playable {
  void play() {
    System.out.println("Saxophone Play");
  }
}




package MST1;
import music.Playable;
import music.string.Veena;
import music.wind.Saxophone;

public class testClass{
  public static void main(String args[]) {
    Veena v = new Veena();
    Saxophone s = new Saxophone();
    Playable pv, ps; 
    pv = new Veena();
    ps = new Saxophone();
    
    v.play();
    s.play();
    
    pv.play(); 
    ps.play(); 
  }
}
