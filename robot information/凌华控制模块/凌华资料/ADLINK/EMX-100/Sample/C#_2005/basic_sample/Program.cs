using System;
using System.Collections.Generic;
using System.Windows.Forms;
using System.Security.Principal;
using System.Diagnostics;
namespace basic_sample
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            WindowsIdentity identity = WindowsIdentity.GetCurrent();
            WindowsPrincipal principal = new WindowsPrincipal(identity);

            if (!principal.IsInRole(WindowsBuiltInRole.Administrator))
            {
                ProcessStartInfo psi = new ProcessStartInfo();
                psi.FileName = Application.ExecutablePath;
                psi.Verb = "runas";
                try
                {
                    Process.Start(psi);
                    Application.Exit();
                }
                catch (Exception eee)
                {
                    MessageBox.Show(eee.Message);
                }
            }
            else
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                Application.Run(new Form1());
            }
            //Application.EnableVisualStyles();
            //Application.SetCompatibleTextRenderingDefault(false);
            //Application.Run(new Form1());
        }
    }
}