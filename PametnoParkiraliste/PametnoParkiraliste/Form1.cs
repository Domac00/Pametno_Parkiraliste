using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace PametnoParkiraliste
{
    public partial class Form1 : Form
    {
        
        public SerialPort myport = new SerialPort();
        public Color BojaPozadnia = new Color();
        public Color BojaNav = new Color();
        
        double rp;
        double gp;
        double bp;
        double rn;
        double gn;
        double bn;  
        public int brz;
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //List<String> tList = new List<String>();
            //portBox.Items.Clear();

            //foreach (string s in SerialPort.GetPortNames())
            //{
            //    tList.Add(s);
            //}

            //tList.Sort();
            //portBox.Items.Add("Odaberi port...");
            //portBox.Items.AddRange(tList.ToArray());
            //portBox.SelectedIndex = 0;


            //var portNames = SerialPort.GetPortNames();
            //foreach (var port in portNames)
            //{
            //    label5.Text = port;
            //}
            colorDialog1.AllowFullOpen = false;
            
            myport.BaudRate = 9600;
            myport.PortName = "COM6";
            myport.WriteTimeout = 1000;
            //myport.Open();
            //if (myport.IsOpen) { MessageBox.Show("ok"); }
            
            

            //brzina nav
            brzina.Minimum = 5;
            brzina.Maximum = 220;
            brzina.SmallChange = 5;
            brzina.LargeChange = 10;

           var portNames = SerialPort.GetPortNames();
            
            portBox.DataSource = portNames;
            
            
        }

        


        private void testButton_Click(object sender, EventArgs e)
        {
            
            if (!myport.IsOpen)
            {
                myport.Open();
            }
            byte[] buffer = new byte[2];
            buffer[0] = Convert.ToByte(120);
            buffer[1] = Convert.ToByte(80);

            myport.Write(buffer, 0, 2);

            myport.Close();
        }

        private void Send_Click(object sender, EventArgs e)
        {
            
                rp = BojaPozadnia.R / 3;
                gp = BojaPozadnia.G / 3;
                bp = BojaPozadnia.B / 3;
                rn = BojaNav.R / 3;
                gn = BojaNav.G / 3;
                bn = BojaNav.B / 3;
                Math.Round(rp);
                Math.Round(gp);
                Math.Round(bp);
                Math.Round(rn);
                Math.Round(gn);
                Math.Round(bn);

                brz = 250 - brzina.Value;
                if (!myport.IsOpen)
                {


                try
                {
                    
                    myport.Open();
                }

                catch (Exception ex)
                {
                    MessageBox.Show("greska");
                }
                

            }

            if (myport.IsOpen)
            {

                byte[] buffer = new byte[7];
                buffer[0] = Convert.ToByte(rp);
                buffer[1] = Convert.ToByte(gp);
                buffer[2] = Convert.ToByte(bp);
                buffer[3] = Convert.ToByte(rn);
                buffer[4] = Convert.ToByte(gn);
                buffer[5] = Convert.ToByte(bn);
                buffer[6] = Convert.ToByte(brz);

                try
                {


                    myport.Write(buffer, 0, 7);
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Pokusaj promjeniti serial port.","Greska");
                }



            }
            
            
        }

       
        private void portBox_SelectedValueChanged(object sender, EventArgs e)
        {
            if (myport.IsOpen)
            {
                myport.Close();
            }
            myport.BaudRate = 9600;
            myport.PortName = portBox.SelectedItem.ToString();

            //myport.BaudRate = 9600;
            //myport.PortName = portBox.SelectedItem.ToString();
        }

        private void bojaPozButt_Click(object sender, EventArgs e)
        {
            

            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                BojaPozadnia = colorDialog1.Color;
                bojaPozButt.BackColor = BojaPozadnia;
            }
        }

        private void BojaNavButt_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                BojaNav = colorDialog1.Color;
                BojaNavButt.BackColor = BojaNav;
            }

        }

       

        private void Button1_Click(object sender, EventArgs e)
        {
            // if (!myport.IsOpen)
            //{
            //    myport.Open();
            //}

            //var a = myport.ReadExisting();

            //slobodnaMjestalb.Text = a.ToString();
            //myport.Close();

            

                if (!myport.IsOpen)
                {
                try
                {
                    myport.Open();
                }

                catch (Exception ex)
                {
                    MessageBox.Show("Pokusaj promjeniti serial port.", "Greska");
                }
              
                }

            if (myport.IsOpen)
            {
                byte[] buffer = new byte[7];
                buffer[0] = Convert.ToByte(15);
                buffer[1] = Convert.ToByte(15);
                buffer[2] = Convert.ToByte(15);
                buffer[3] = Convert.ToByte(0);
                buffer[4] = Convert.ToByte(30);
                buffer[5] = Convert.ToByte(0);
                buffer[6] = Convert.ToByte(80);

                try
                {
                    myport.Write(buffer, 0, 7);
                }
                catch (Exception ex)
                {
                    MessageBox.Show("Pokusaj promjeniti serial port.", "Greska");
                }




                bojaPozButt.BackColor = Color.White;
                BojaNavButt.BackColor = Color.Green;
            }
            
        }

        private void osvjeziButt_Click(object sender, EventArgs e)
        {
            var portNames = SerialPort.GetPortNames();

            portBox.DataSource = portNames;
        }

        private void portBox_TextUpdate(object sender, EventArgs e)
        {
            myport.BaudRate = 9600;
            myport.PortName = portBox.SelectedItem.ToString();

        }

        private void portBox_Click(object sender, EventArgs e)
        {

            myport.BaudRate = 9600;
            myport.PortName = portBox.SelectedItem.ToString();
        }



        //serial event


    }
}
