namespace PametnoParkiraliste
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Send = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.brzina = new System.Windows.Forms.TrackBar();
            this.label7 = new System.Windows.Forms.Label();
            this.portBox = new System.Windows.Forms.ComboBox();
            this.bojaPozButt = new System.Windows.Forms.Button();
            this.BojaNavButt = new System.Windows.Forms.Button();
            this.Default = new System.Windows.Forms.Button();
            this.imageList1 = new System.Windows.Forms.ImageList(this.components);
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.osvjeziButt = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.brzina)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // Send
            // 
            this.Send.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.Send.Font = new System.Drawing.Font("Segoe Print", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Send.Location = new System.Drawing.Point(125, 345);
            this.Send.Name = "Send";
            this.Send.Size = new System.Drawing.Size(348, 177);
            this.Send.TabIndex = 4;
            this.Send.Text = "Pošalji";
            this.Send.UseVisualStyleBackColor = true;
            this.Send.Click += new System.EventHandler(this.Send_Click);
            // 
            // colorDialog1
            // 
            this.colorDialog1.SolidColorOnly = true;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Segoe Print", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(12, 48);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(172, 33);
            this.label5.TabIndex = 10;
            this.label5.Text = "Pozadinska Boja";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Segoe Print", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label6.Location = new System.Drawing.Point(310, 48);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(163, 33);
            this.label6.TabIndex = 11;
            this.label6.Text = "Boja navođenja";
            // 
            // brzina
            // 
            this.brzina.BackColor = System.Drawing.Color.Maroon;
            this.brzina.CausesValidation = false;
            this.brzina.Location = new System.Drawing.Point(650, 119);
            this.brzina.Name = "brzina";
            this.brzina.Size = new System.Drawing.Size(265, 45);
            this.brzina.TabIndex = 16;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.BackColor = System.Drawing.Color.White;
            this.label7.Font = new System.Drawing.Font("Segoe Print", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.label7.Location = new System.Drawing.Point(644, 48);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(185, 33);
            this.label7.TabIndex = 17;
            this.label7.Text = "Brzina navođenja";
            // 
            // portBox
            // 
            this.portBox.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.portBox.FormattingEnabled = true;
            this.portBox.Location = new System.Drawing.Point(650, 210);
            this.portBox.Name = "portBox";
            this.portBox.Size = new System.Drawing.Size(155, 21);
            this.portBox.TabIndex = 19;
            this.portBox.Text = "Odaberi Serial Port";
            this.portBox.TextUpdate += new System.EventHandler(this.portBox_TextUpdate);
            this.portBox.SelectedValueChanged += new System.EventHandler(this.portBox_SelectedValueChanged);
            // 
            // bojaPozButt
            // 
            this.bojaPozButt.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.bojaPozButt.AutoSize = true;
            this.bojaPozButt.Font = new System.Drawing.Font("Segoe Print", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.bojaPozButt.Location = new System.Drawing.Point(12, 96);
            this.bojaPozButt.Name = "bojaPozButt";
            this.bojaPozButt.Size = new System.Drawing.Size(284, 202);
            this.bojaPozButt.TabIndex = 20;
            this.bojaPozButt.Text = "Promjeni boju";
            this.bojaPozButt.UseVisualStyleBackColor = true;
            this.bojaPozButt.Click += new System.EventHandler(this.bojaPozButt_Click);
            // 
            // BojaNavButt
            // 
            this.BojaNavButt.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left)));
            this.BojaNavButt.AutoSize = true;
            this.BojaNavButt.Font = new System.Drawing.Font("Segoe Print", 27.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.BojaNavButt.Location = new System.Drawing.Point(302, 96);
            this.BojaNavButt.Name = "BojaNavButt";
            this.BojaNavButt.Size = new System.Drawing.Size(302, 202);
            this.BojaNavButt.TabIndex = 21;
            this.BojaNavButt.Text = "Promjeni boju";
            this.BojaNavButt.UseVisualStyleBackColor = true;
            this.BojaNavButt.Click += new System.EventHandler(this.BojaNavButt_Click);
            // 
            // Default
            // 
            this.Default.Anchor = System.Windows.Forms.AnchorStyles.Left;
            this.Default.Font = new System.Drawing.Font("Segoe Print", 26.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(238)));
            this.Default.Location = new System.Drawing.Point(125, 577);
            this.Default.Name = "Default";
            this.Default.Size = new System.Drawing.Size(348, 95);
            this.Default.TabIndex = 22;
            this.Default.Text = "Vrati zadano";
            this.Default.UseVisualStyleBackColor = true;
            this.Default.Click += new System.EventHandler(this.Button1_Click);
            // 
            // imageList1
            // 
            this.imageList1.ColorDepth = System.Windows.Forms.ColorDepth.Depth8Bit;
            this.imageList1.ImageSize = new System.Drawing.Size(16, 16);
            this.imageList1.TransparentColor = System.Drawing.Color.Transparent;
            // 
            // pictureBox1
            // 
            this.pictureBox1.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("pictureBox1.BackgroundImage")));
            this.pictureBox1.Location = new System.Drawing.Point(638, 299);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(288, 389);
            this.pictureBox1.TabIndex = 24;
            this.pictureBox1.TabStop = false;
            // 
            // osvjeziButt
            // 
            this.osvjeziButt.Location = new System.Drawing.Point(811, 210);
            this.osvjeziButt.Name = "osvjeziButt";
            this.osvjeziButt.Size = new System.Drawing.Size(104, 23);
            this.osvjeziButt.TabIndex = 26;
            this.osvjeziButt.Text = "Provjeri Portove";
            this.osvjeziButt.UseVisualStyleBackColor = true;
            this.osvjeziButt.Click += new System.EventHandler(this.osvjeziButt_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 696);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(103, 13);
            this.label1.TabIndex = 27;
            this.label1.Text = "Bluetooth PIN: 1234";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(960, 761);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.osvjeziButt);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.Default);
            this.Controls.Add(this.BojaNavButt);
            this.Controls.Add(this.bojaPozButt);
            this.Controls.Add(this.portBox);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.brzina);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.Send);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = " ";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.brzina)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Button Send;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TrackBar brzina;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox portBox;
        private System.Windows.Forms.Button bojaPozButt;
        private System.Windows.Forms.Button BojaNavButt;
        private System.Windows.Forms.Button Default;
        private System.Windows.Forms.ImageList imageList1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button osvjeziButt;
        private System.Windows.Forms.Label label1;
    }
}

