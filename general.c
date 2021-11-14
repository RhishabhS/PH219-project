void general(){
const char *root_file="/home/rhishabh/ph219_project/file1/13TeV_CR0_RHoff.root";//Enter path of root file here    
const char *files[14]={"pytree;100","pytree;99","pytree2040;28","pytree2040;27","pytree4060;24","pytree4060;23","pytree020;24","pytree020;23","pytree6080;16","pytree6080;15","pytree80100;7","pytree80100;6","pytree100;3","pytree100;2"};
TH1D *hist=new TH1D("hist","acceptance region",1000,0,20000000); //count of eta>1.5=60623206
for(int k=0;k<12;k++){
TTree *t=new TTree("t","myTree");
TFile *f=new TFile(root_file); 
Int_t pid[192];
Int_t ntrack;
Double_t pT[192]; 
Double_t rap[192];
Double_t eta[192];
Double_t phi[192];
gDirectory->GetObject(files[k],t);
t->SetBranchAddress("pid",pid);
t->SetBranchAddress("pT",pT);
t->SetBranchAddress("eta",eta);
t->SetBranchAddress("rap",rap);
t->SetBranchAddress("phi",phi);
t->SetBranchAddress("ntrack",&ntrack);
size_t n=(size_t)t->GetEntries();
for(size_t i=0;i<n;i++){
    t->GetEntry(i); 
    //looping through event
    for(Int_t j=0;j<ntrack;j++){
    //looping through particles
    //enter conditions here
    }
}
}
hist->Draw("plotx");
}