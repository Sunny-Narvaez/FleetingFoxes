import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import java.awt.Dimension;
import java.awt.Toolkit;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Juego extends JFrame implements KeyListener {

    public static final int WIDTH = 640, HEIGHT = 600;
    private JLabel zorro;
    private int xPosition, yPosition;

    public Juego() {
        setTitle("Space Ship Game");
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);

        // Obtener la dimensión de la pantalla para centrar la ventana
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        int x = (screenSize.width - WIDTH) / 2;
        int y = (screenSize.height - HEIGHT) / 2;
        setLocation(x, y);

        // Inicializa las coordenadas del zorro
        xPosition = 220;
        yPosition = 302;

        // Crea un JLabel con la imagen del zorro_walk.gif
        zorro = new JLabel(
                new ImageIcon("zorro_walk.gif"));

        // Establece el diseño del JFrame como null para superponer los componentes
        setLayout(null);

        // Establece el tamaño y la posición de la imagen frontal en la esquina superior
        // izquierda
        zorro.setBounds(xPosition, yPosition, zorro.getIcon().getIconWidth(),
                zorro.getIcon().getIconHeight());

        // Agrega el KeyListener a la ventana
        addKeyListener(this);

        // Establece el enfoque en la ventana para que pueda recibir eventos de teclado
        setFocusable(true);
        setFocusTraversalKeysEnabled(false);

        // Fondos
        JLabel fondoUno = new JLabel(new ImageIcon("uno.png"));
        JLabel fondoDulces = new JLabel(
                new ImageIcon("4 dulces-export.gif"));

        fondoDulces.setBounds(0, 0, WIDTH, HEIGHT); // Ajustar las coordenadas
        fondoUno.setBounds(0, -100, WIDTH, HEIGHT); // Ajustar las coordenadas

        // Agregar los fondos al JFrame
        add(zorro);
        add(fondoDulces);
        add(fondoUno);

        // Hacer el JFrame visible
        setVisible(true);
    }

    public static void main(String[] args) {
        new Juego();
    }

    // Implementa los métodos de KeyListener
    @Override
    public void keyTyped(KeyEvent e) {

    }

    @Override
    public void keyPressed(KeyEvent e) {
        int keyCode = e.getKeyCode();

        // Controlar el movimiento del zorro
        int stepSize = 15; // Tamaño del paso

        if (keyCode == KeyEvent.VK_A) {
            xPosition -= stepSize; // Mover el zorro hacia la izquierda
        } else if (keyCode == KeyEvent.VK_D) {
            xPosition += stepSize; // Mover el zorro hacia la derecha
        } else if (keyCode == KeyEvent.VK_W) {
            yPosition -= stepSize; // Mover el zorro hacia arriba
        } else if (keyCode == KeyEvent.VK_S) {
            yPosition += stepSize; // Mover el zorro hacia abajo
        }

        // Actualizar la posición del zorro
        zorro.setBounds(xPosition, yPosition, zorro.getIcon().getIconWidth(),
                zorro.getIcon().getIconHeight());
    }

    @Override
    public void keyReleased(KeyEvent e) {

    }
}
