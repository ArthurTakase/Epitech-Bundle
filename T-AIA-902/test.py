import torch, platform, sys
print("PyTorch :", torch.__version__)
print("CUDA dispo :", torch.cuda.is_available())
print("CUDA build :", torch.version.cuda)
print("GPU détecté:", torch.cuda.get_device_name(0) if torch.cuda.is_available() else "—")
