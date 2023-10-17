import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Dimension;
import java.awt.Toolkit;

public class Juego extends JFrame {

    public static final int WIDTH = 640, HEIGHT = 600;

    public Juego() {
        setTitle("Space Ship Game");
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        // Obtén la dimensión de la pantalla para centrar la ventana
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (screenSize.width - WIDTH) / 2;
        int y = (screenSize.height - HEIGHT) / 2;
        setLocation(x, y);

        // Crea tres JLabels con las imágenes
        JLabel imagenFrontal = new JLabel(
                new ImageIcon("texturas/zorro_walk.gif"));
        JLabel fondo1 = new JLabel(new ImageIcon("texturas/4 dulces-export.gif"));
        JLabel fondo2 = new JLabel(new ImageIcon("texturas/cielox256-export.png"));

        // Establece el diseño del JFrame como null para superponer los componentes
        setLayout(null);

        // Establece el tamaño y la posición de los fondos
        fondo1.setBounds(0, HEIGHT - fondo1.getIcon().getIconHeight(), WIDTH, fondo1.getIcon().getIconHeight());
        fondo2.setBounds(0, 0, WIDTH, HEIGHT);

        // Calcula la posición para centrar la imagenFrontal
        int centroX = (WIDTH - imagenFrontal.getIcon().getIconWidth()) / 2;
        int centroY = (HEIGHT - imagenFrontal.getIcon().getIconHeight()) / 2;

        // Establece el tamaño y la posición de la imagenFrontal en el centro
        imagenFrontal.setBounds(centroX, centroY, imagenFrontal.getIcon().getIconWidth(),
                imagenFrontal.getIcon().getIconHeight());

        // Agrega los componentes al JFrame (el orden importa, los últimos agregados
        // estarán más al frente)
        add(imagenFrontal);
        add(fondo1);
        add(fondo2);

        fondo1.setOpaque(false);
        fondo2.setOpaque(false);

        // Hacer los componentes visibles
        fondo1.setVisible(true);
        fondo2.setVisible(true);
        imagenFrontal.setVisible(true);

        // Hacer el JFrame visible
        setVisible(true);
    }

    public static void main(String[] args) {
        new Juego();
    }
}
